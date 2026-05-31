# COD:MW4 - PUBLIC DOCUMENTATION

## Game Design Documentation (Public Version)

**Version:** 3.0.0  
**Last Updated:** 2026-05-31  
**Project:** COD:MW4 - Modern Warfare 4 RPG Mod for Counter-Strike 1.6

> **DISCLAIMER:** This document provides an overview of game features and design philosophy. It does not contain implementation details, source code, or technical internals. Full documentation is available to approved developers only.

---

## DOCUMENT NAVIGATION

| Document | Description |
|----------|-------------|
| `01_overview.md` | Project overview and philosophy (this file) |
| `02_gameplay_features.md` | Complete gameplay features list |
| `03_class_system.md` | Class mechanics and abilities |
| `04_perk_system.md` | Perk mechanics and effects |
| `05_economy_system.md` | Currency, shop, and rewards |
| `06_progression_system.md` | Leveling, stats, and mastery |
| `07_streak_system.md` | Daily, weekly, and kill streaks |
| `08_gap_protection.md` | Underdog system for fair PvP |
| `09_cosmetic_system.md` | Kill effects and custom knives |
| `10_technical_specs.md` | Platform requirements |

---

# DOCUMENT 01: PROJECT OVERVIEW

## What is COD:MW4?

**COD:MW4** is a complete remake of the classic RPG modification for Counter-Strike 1.6, built from scratch for AMX Mod X 1.9. It combines tactical first-person shooting with deep role-playing progression, class-based abilities, and persistent rewards.

The mod transforms CS 1.6 into an experience inspired by Call of Duty: Modern Warfare, adding levels, attributes, classes, perks, quests, achievements, and a full in-game economy.

## Core Philosophy

- **Keep what works well** – Stable systems like database persistence and clan support are preserved.
- **Upgrade gradually** – New features are added without breaking existing structure.
- **Keep It Simple, Stupid (KISS)** – Every feature is implemented in the simplest working way. No over‑engineering.
- **Zero placeholders** – Every promised function is fully implemented. No `// TODO`, stubs, or empty callbacks.
- **Integrity, honesty, full commitment** – The mod is built with care and transparency.

## Key Features at a Glance

| Category | Features |
|----------|----------|
| **Progression** | Level 1–250 + Mastery 1–250, 5 upgradeable attributes |
| **Combat** | Damage multiplier, damage reduction, speed bonus, HP bonus, RNG modification |
| **Classes** | 4 unique classes (Free, VIP, Credit, Custom access) |
| **Perks** | 4 equippable perks (passive and active abilities) |
| **Economy** | Gold, Credits, Fragments, CS Money – earn and spend |
| **Streaks** | Daily login, weekly play, kill, round win, quest streaks |
| **Gap Protection** | Underdog system for fair fights between players of different levels |
| **Cosmetics** | 9 kill effects + 5 custom knife models – permanent unlocks |
| **Quality of Life** | Press M for menu, scrolling HUD, 40+ sound effects, 100 armor every spawn, unlimited ammo |

## How It Plays

1. **Choose a class** – Each class has unique HP, speed, visibility, weapons, and an active skill.
2. **Equip a perk** – Purchase perks with gold to gain passive or round‑based advantages.
3. **Level up** – Gain EXP from kills, quests, streaks, and achievements. Spend stat points to increase INT, STR, STA, CON, or FOR.
4. **Earn currency** – Gold, Credits, Fragments, and CS Money from various activities. Buy items from the shop.
5. **Complete quests & achievements** – Micro‑tasks and heroic milestones grant bonus rewards.
6. **Build streaks** – Daily login, weekly play, kill streak, round streak, and quest streak all boost your XP gain.
7. **Use the underdog system** – When facing much higher‑level opponents, gain stacking bonuses that help you fight back.
8. **Customize your look** – Unlock kill effects and custom knives permanently.

## Server Community

COD:MW4 is designed for active server communities. It includes:
- Full leaderboard system (Top 15)
- Monthly resets with rewards for top players
- Clan system with damage bonuses and round bonuses
- VIP system with exclusive benefits
- Detailed admin commands and logging

## Join the Community

- **Discord Server:** https://discord.gg/ZaGdCPGWzd
- **GitHub Repository:** https://github.com/amxxscripter412-hub/COD-MW4

---

*This documentation is for public consumption. Full source code and technical documentation are available to approved contributors only.*
