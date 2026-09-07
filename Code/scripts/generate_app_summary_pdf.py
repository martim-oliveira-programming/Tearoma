from pathlib import Path

from reportlab.lib import colors
from reportlab.lib.pagesizes import A4
from reportlab.pdfbase.pdfmetrics import stringWidth
from reportlab.pdfgen import canvas


ROOT = Path(__file__).resolve().parents[1]
OUTPUT = ROOT / "output" / "pdf" / "tearoma-app-summary.pdf"


TITLE = "Tearoma App Summary"

WHAT_IT_IS = (
    "Tearoma is a single-player terminal RPG written in C++. "
    "This repo currently implements a text-driven adventure loop with chapter-based story progression, "
    "character setup, and JSON save/load support."
)

WHO_ITS_FOR = (
    "Primary user: players who enjoy story-first, choice-driven fantasy RPGs in a command-line format, "
    "especially early adopters comfortable with an in-progress game prototype."
)

FEATURES = [
    "Starts a new game or continues from an existing save.",
    "Prompts for player setup including name, hair color, and gender.",
    "Runs chapter-based story scenes through timed text dialogue.",
    "Tracks player stats, build, rank, mana, items, abilities, summons, and party members.",
    "Stores story chapter, events, and path choices as progression state.",
    "Saves and loads progress as JSON in saves/save.json.",
    "Defines item, armour, weapon, consumable, NPC, and summon systems for expansion.",
]

ARCHITECTURE = [
    "Entry loop: src/game/main.cpp seeds RNG and switches between MENU, PLAYING, and QUIT states.",
    "UI/input: src/game/Menu.cpp and src/systems/Dialogue.cpp print prompts, collect line input, and map numbered choices.",
    "Game state: Player, Story, Npc/Summon, Ability, and Item classes hold core adventure data.",
    "Persistence: src/engine/Save.cpp serializes player, story, and NPC state with vendored nlohmann/json.",
    "Data flow: launch -> menu -> create/load state -> Story::play_chapter(...) -> save_game(...) after progression.",
    "Services/backend: Not found in repo.",
]

RUN_STEPS = [
    "Requirements: g++ with C++17 support and make; additional setup docs are Not found in repo.",
    "From the repo root, run: make",
    "Start the game with: ./Tearoma",
    "Optional shortcut: make run",
]


def wrap_text(text, font_name, font_size, max_width):
    words = text.split()
    lines = []
    current = ""
    for word in words:
        candidate = word if not current else f"{current} {word}"
        if stringWidth(candidate, font_name, font_size) <= max_width:
            current = candidate
        else:
            if current:
                lines.append(current)
            current = word
    if current:
        lines.append(current)
    return lines


def draw_wrapped(c, text, x, y, font_name, font_size, max_width, leading, color=colors.black):
    c.setFont(font_name, font_size)
    c.setFillColor(color)
    lines = wrap_text(text, font_name, font_size, max_width)
    for line in lines:
        c.drawString(x, y, line)
        y -= leading
    return y


def draw_bullets(c, items, x, y, width, font_name="Helvetica", font_size=9.5, bullet_indent=10, leading=12):
    c.setFont(font_name, font_size)
    for item in items:
        wrapped = wrap_text(item, font_name, font_size, width - bullet_indent - 6)
        for index, line in enumerate(wrapped):
            if index == 0:
                c.drawString(x, y, "-")
                c.drawString(x + bullet_indent, y, line)
            else:
                c.drawString(x + bullet_indent, y, line)
            y -= leading
        y -= 2
    return y


def main():
    OUTPUT.parent.mkdir(parents=True, exist_ok=True)
    c = canvas.Canvas(str(OUTPUT), pagesize=A4)
    width, height = A4

    margin_x = 46
    top = height - 44
    body_width = width - (margin_x * 2)

    c.setTitle(TITLE)

    c.setFillColor(colors.HexColor("#153b50"))
    c.setFont("Helvetica-Bold", 20)
    c.drawString(margin_x, top, TITLE)

    c.setStrokeColor(colors.HexColor("#8db3c7"))
    c.setLineWidth(1)
    c.line(margin_x, top - 8, width - margin_x, top - 8)

    y = top - 28

    def section(title, body=None, bullets=None):
        nonlocal y
        c.setFillColor(colors.HexColor("#153b50"))
        c.setFont("Helvetica-Bold", 11)
        c.drawString(margin_x, y, title)
        y -= 14
        if body:
            y = draw_wrapped(c, body, margin_x, y, "Helvetica", 9.5, body_width, 12)
            y -= 4
        if bullets:
            y = draw_bullets(c, bullets, margin_x, y, body_width)
            y -= 2

    section("What It Is", WHAT_IT_IS)
    section("Who It's For", WHO_ITS_FOR)
    section("What It Does", bullets=FEATURES)
    section("How It Works", bullets=ARCHITECTURE)
    section("How To Run", bullets=RUN_STEPS)

    c.setFillColor(colors.HexColor("#5d6a72"))
    c.setFont("Helvetica-Oblique", 8)
    c.drawRightString(width - margin_x, 18, "Repo evidence only; missing details marked explicitly.")

    c.save()
    print(OUTPUT)


if __name__ == "__main__":
    main()
