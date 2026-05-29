COD:MW4 - Modern Warfare 4 RPG Mod for Counter-Strike 1.6

Project Overview

COD:MW4 is a ground-up remake of the COD Mod RPG for Counter-Strike 1.6, built from scratch for AMX Mod X 1.9. This project aims to deliver a complete RPG experience with leveling system, classes, perks, streaks, shop, and cosmetic system.

Repository Structure

COD-MW4/
+-- docs/               Complete game design documentation (50+ pages)
+-- include/            cod.inc (API contract)
+-- .github/            Issue and pull request templates
+-- scripts/            Python tool suite (coming soon)

Project Status

Phase 1: Planning and Design - COMPLETE
Phase 2: Core Development - IN PROGRESS
Phase 3: Content and Polish - NOT STARTED
Phase 4: Testing and Launch - NOT STARTED

Looking for Team Members

We are currently looking for the following positions:

1. Hoster (1 position)

Requirements: Own a Counter-Strike 1.6 server or willing to host one. Provide stable 24/7 uptime. Basic knowledge of AMX Mod X installation.

2. Programmer (unlimited positions)

Requirements: Proficient in PAWN language and AMX Mod X 1.9. Understand fakemeta, hamsandwich, and SQLite. Can write clean code following project standards. Able to commit minimum 5 hours per week.

IMPORTANT: Programmers are strictly prohibited from sharing any source code with anyone outside the core team. All code is confidential.

3. Tester (unlimited positions)

Requirements: Own Counter-Strike 1.6. Able to play regularly on test server. Detail-oriented and can write clear bug reports. Willing to test new features and provide feedback.

4. Discord Moderator (unlimited positions)

Requirements: Fluent in English. Active on Discord. Understand community management basics. Able to enforce server rules professionally.

Benefits for Team Members

All accepted team members will receive the following benefits:

Full Access: Once the server is operational, you will get full access to the server including admin privileges and all VIP features.

Revenue Sharing: You will receive a share of all revenue generated from:
- VIP subscriptions on the server
- Donations from players
- Any other monetization methods implemented

Credit and Recognition: Your name will be permanently listed in CONTRIBUTORS.md and in the plugin credits.

Early Access: You will be part of the development process from the beginning and can shape the project direction.

Priority Support: Direct communication with the project lead for any questions or assistance.

How to Apply

Step 1: Join our Discord server
Link: https://discord.gg/ZaGdCPGWzd

Step 2: Introduce yourself in the introductions channel with your name, experience, and desired role.

Step 3: Fill out the application form in the applications channel.

Step 4: For programmer applicants, a quick voice interview will be scheduled.

Code Standards for Programmers

The following rules are mandatory for all programmers:

- Use 4-space indentation, not tabs
- Place opening braces on a new line for functions
- Group global variables at the top of the file
- Use descriptive variable names
- No SQL_ThreadQuery (use sync blocking only)
- No PreThink or PostThink (use set_task)
- No enum struct, methodmap, or char[]
- No TODO comments, no FIXME comments, no stubs, no placeholders
- No empty functions that only return 0
- Every function must have full implementation
- Never share any source code with anyone outside the team

Gameplay Features

The following features are implemented or being implemented:

- 100 kevlar plus helmet every spawn
- Unlimited BP ammo
- Press M key for main menu
- Scrolling HUD with real-time information
- 40 sound effects for immersive experience
- RPG system with level 1-250 plus mastery 1-250
- Five attributes: INT, STR, STA, CON, FOR
- Four classes: Sapper (FREE), Assassin (VIP), Ghost (CREDIT), Chronos (CUSTOM)
- Four perks: Silent Boots, Quick Reload, Immortality, Set Stunter
- Shop system with nine items plus Kulawangsa Shield
- Five streak types: daily, weekly, kill, round, quest
- Gap protection with 5-stack underdog system
- Cosmetic system with nine kill effects and five custom knives
- Economy with gold, credits, fragments, and CS money
- Leaderboard reset every 60 days with rewards

Disclaimer

COD:MW4 is a ground-up remake inspired by the gameplay concepts of COD Mod Legacy created by OZone.

No code was copied from the original mod. All implementations are original and written from scratch. This project is not affiliated with or endorsed by OZone.

Credit and respect to OZone for creating the original COD Mod that inspired this project.

Contact

Discord Server: https://discord.gg/ZaGdCPGWzd
Project Lead: El (Nuel)
