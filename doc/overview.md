# COD:MW4 - PUBLIC DOCUMENTATION

## Game Design Documentation (Public Version)

**Version:** 3.0.0  
**Last Updated:** 2026-05-29  
**Project:** COD:MW4 - Modern Warfare 4 RPG Mod for Counter-Strike 1.6

## DISCLAIMER : THIS DOCUMENT DOESNT IMPLEMENT ALL CODE. ONLY DEV GOT THE PRIVATE DOC

---

## DOCUMENT NAVIGATION

| Document | Description |
|----------|-------------|
| `01_overview.md` | Project overview and philosophy |
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

## DOCUMENT 01: PROJECT OVERVIEW

# COD:MW4 - Project Overview

## What is COD:MW4?

COD:MW4 is a ground-up remake of the classic RPG modification for Counter-Strike 1.6, built from scratch for AMX Mod X 1.9.

## Philosophy

- Keep what works well
- Upgrade gradually without breaking existing structure
- Keep It Simple, Stupid (KISS)
- Zero placeholders - every promised function has full implementation
- Integrity, honesty, and full commitment

## Key Features at a Glance

- Level system: 1 to 250 plus Mastery 1 to 250
- Five character attributes
- Four unique classes with different access tiers
- Four equippable perks
- Shop with 9 items
- Five types of streak systems
- Gap protection for balanced PvP
- Cosmetic system with permanent unlocks
- Full SQLite database persistence




## DOCUMENT 02: GAMEPLAY FEATURES


# COD:MW4 - Gameplay Features

## Core Mechanics

| Feature | Description |
|---------|-------------|
| Level System | Progress from level 1 to 250 |
| Mastery System | Continue progression beyond level 250 (1-250) |
| Attribute System | Five stats that affect gameplay |
| Class System | Choose from 4 unique classes |
| Perk System | Equip 1 perk for passive or active benefits |
| Shop System | Buy items using in-game currency |

## Combat Features

| Feature | Description |
|---------|-------------|
| 100 Kevlar + Helmet | Granted every spawn |
| Unlimited BP Ammo | No ammunition restrictions |
| Damage Multiplier | Based on INT attribute |
| Damage Reduction | Based on STR attribute |
| Speed Bonus | Based on STA attribute |
| HP Bonus | Based on CON attribute |
| RNG Modification | Based on FOR attribute |

## Quality of Life

| Feature | Description |
|---------|-------------|
| Press M | Opens main menu |
| Scrolling HUD | Rotating information display |
| 40+ Sound Effects | Immersive audio feedback |
| CS Shop | Disabled (replaced by COD shop) |


## DOCUMENT 03: CLASS SYSTEM


# COD:MW4 - Class System

## Available Classes

### Sapper (Free Access)

| Aspect | Details |
|--------|---------|
| Role | Expert in mines and traps |
| HP Bonus | +25 |
| Speed | 1.0 (normal) |
| Visibility | 100% (normal) |
| Weapons | Knife, P90 |
| Active Skill | Deploy mine |
| Promotion Path | Technician (+30 HP, +5% speed) |

### Assassin (VIP Access)

| Aspect | Details |
|--------|---------|
| Role | Master of stealth and knife combat |
| HP Bonus | -25 |
| Speed | 1.5 (faster) |
| Visibility | 5% (nearly invisible) |
| Weapons | Knife, USP |
| Passive Abilities | Silent footsteps, invisibility when holding knife |
| Special | Knife deals double damage; secondary attack instant kill |

### Ghost (Credit Access)

| Aspect | Details |
|--------|---------|
| Role | Silent and invisible |
| HP Bonus | 0 |
| Speed | 1.2 (faster) |
| Visibility | 50% (semi-visible) |
| Weapons | Knife, MP5 Navy |
| Passive | Silent footsteps |
| Active Skill | Teleport |

### Chronos (Custom Access)

| Aspect | Details |
|--------|---------|
| Role | Master of time |
| HP Bonus | 0 |
| Speed | 1.1 (slightly faster) |
| Visibility | 100% (normal) |
| Weapons | Knife, AK47 |
| Active Skill | Position recall (save position, teleport back within 3 seconds) |
| Cooldown | 40 seconds |

## Class Access Tiers

| Tier | Access Method |
|------|---------------|
| Free | Available to all players |
| VIP | Requires VIP status on server |
| Credit | Purchase with in-game Credit currency |
| Custom | Special access for custom class holders |


## DOCUMENT 04: PERK SYSTEM


# COD:MW4 - Perk System

## Available Perks

### Silent Boots

| Aspect | Details |
|--------|---------|
| Type | Passive |
| Cost | 100 (in-game currency) |
| Effect | No footstep sounds |
| When Active | Always while perk is equipped |

### Quick Reload

| Aspect | Details |
|--------|---------|
| Type | Passive |
| Cost | 500 |
| Effect | Reload 30% faster |
| When Active | Always while perk is equipped |

### Immortality

| Aspect | Details |
|--------|---------|
| Type | Passive (per round) |
| Cost | 800 |
| Effect | Survive one fatal hit per round |
| After Trigger | Restored to 50 HP, brief invincibility |

### Set Stunter

| Aspect | Details |
|--------|---------|
| Type | Passive with weapon |
| Cost | 1000 |
| Effect | Custom MP5 with 1/7 chance to instantly kill |
| Note | Instant kill bypasses normal damage calculation |

## Perk Mechanics

- Players can equip only one perk at a time
- Perks are purchased using in-game currency
- Perks remain active until changed
- Some perks have round-based cooldowns


## DOCUMENT 05: ECONOMY SYSTEM


# COD:MW4 - Economy System

## Currency Types

| Currency | Name | How to Obtain |
|----------|------|---------------|
| Gold | Primary currency | Kills, streaks, quests, achievements |
| Credits | Premium currency | Special events, leaderboard rewards |
| Fragments | Special currency | Boxes, quests, achievements |
| CS Money | CS 1.6 money | Kills, bomb plants, round wins |

## Shop Items

| Item | Cost (CS Money) | Effect |
|------|-----------------|--------|
| Bandage | 3,000 | +50 HP |
| Double Bandage | 5,500 | +100 HP |
| Redbull | 7,000 | +20% speed, reduced gravity for current round |
| Lucky Box | 2,000 | Random reward (gold, XP, credits, fragments) |
| Random Perk | 3,500 | Get a random perk |
| Treasure | 10,000 | +1000 XP + 10% toward next level |
| Super Treasure | 16,000 | +2000 XP + 20% toward next level |
| Armor Regen | 4,500 | Regenerate 5 armor per second |
| Kulawangsa Shield | 16,000 | Block one fatal hit per round |

## Bounty System

| Feature | Description |
|---------|-------------|
| Activation | 5 kill streak |
| Visual | Red glow effect on player |
| Reward for Killer | +50 Gold, +100 XP |
| Additional | Spawns special box on death |

## Legacy Box

| Feature | Description |
|---------|-------------|
| Spawn Chance | 5% on player death |
| Rewards | Fragments, gold, rockets, mines, medkits, dynamite, health, stat adjustments |




## DOCUMENT 06: PROGRESSION SYSTEM


# COD:MW4 - Progression System

## Level System

| Feature | Details |
|---------|---------|
| Base Level Range | 1 to 250 |
| Mastery Range | 1 to 250 (beyond level 250) |
| Visual Display | Shows 250 when mastery level active |
| Background Level | Tracks true level including mastery |

## Attribute System (5 Stats)

| Attribute | Effect | Formula |
|-----------|--------|---------|
| INT (Intelligence) | Damage multiplier | 1.0 + INT * 0.01 |
| INT | Instant kill chance | (INT/100) * 5% (max 25%) |
| STR (Strength) | Damage reduction | 1.0 - STR * 0.005 (max 50% reduction) |
| STR | Anti-instant kill | Reduces enemy instant kill chance |
| STA (Stamina) | Movement speed | 250 * (1.0 + STA * 0.01) (max 500) |
| CON (Condition) | Maximum HP | 100 + (CON * 4) |
| FOR (Fortune) | RNG bonus | Modifies chance-based abilities |
| FOR | Skill cooldown | Reduces cooldown up to 20% |

## EXP System

| Feature | Details |
|---------|---------|
| Base EXP Formula | level² * 7 |
| Time to Level 250 | Approximately 30 days of active play |
| EXP Sources | Kills, streaks, quests, achievements, daily rewards |
| EXP Bonuses | Kill streaks, gap protection underdog bonus |

## Mastery System

- Unlocked after reaching level 250
- 250 additional mastery levels available
- Each mastery level provides continued progression
- Visual level caps at 250 while mastery increases in background


## DOCUMENT 07: STREAK SYSTEM


# COD:MW4 - Streak System

## Five Streak Types

### Daily Streak

| Feature | Details |
|---------|---------|
| Trigger | Daily login |
| Maximum | 8 days |
| Reset Behavior | Resets to day 1 (not zero) on missed login |
| Rewards | XP and Gold increasing with streak length |
| Day 8 Bonus | 1000 XP + 100 Gold |

### Weekly Streak

| Feature | Details |
|---------|---------|
| Trigger | Play at least once per week |
| Tracking | Consecutive weeks played |
| Rewards | Bonus XP and Gold |

### Kill Streak

| Feature | Details |
|---------|---------|
| Trigger | Consecutive kills without dying |
| Bonus | Increased EXP per kill at 5, 10, 15, 20+ streaks |
| Visual | Displayed in HUD |

### Round Streak

| Feature | Details |
|---------|---------|
| Trigger | Consecutive round wins |
| Bonus | Extra gold on round win |

### Quest Streak

| Feature | Details |
|---------|---------|
| Trigger | Complete quests consecutively |
| Penalty | Failing to complete a quest resets streak to 1 |
| Rewards | Bonus EXP on milestone completions |

## Streak Rewards

All streaks provide progressive rewards that increase with streak length. Each streak type has its own reward table with XP, Gold, and special bonuses at milestone intervals.


## DOCUMENT 08: GAP PROTECTION (UNDERDOG SYSTEM)


# COD:MW4 - Gap Protection System

## Overview

The Underdog system activates when players face opponents with significantly higher levels (80+ level difference, not counting mastery). This ensures fair PvP combat.

## Underdog Stacks

| Stack Level | Effect |
|-------------|--------|
| 1 (Bounty Hunter) | +100% EXP on kill + spawn bounty box |
| 2 (Damage Dealer) | Previous + 15% bonus damage vs higher level players |
| 3 (Swift) | Previous + 15% movement speed for 40 seconds after spawn |
| 4 (Tank) | Previous + 15% damage reduction from higher level players |
| 5 (Equalizer) | Previous + Bypass 100% of enemy's STR and armor |

## Stack Mechanics

| Action | Effect on Stacks |
|--------|------------------|
| Death to higher level player | Gain 1 stack |
| Kill higher level player | Lose 3 stacks |
| End of round without kill | Lose 1 stack |
| Maximum stacks | 5 |

## Danger Indicator

When aiming at a significantly higher level enemy, a yellow "DANGER!" indicator flashes near the crosshair.

## EXP Bonus

Killing a significantly higher level player grants 2x normal EXP (stacks with other bonuses).


## DOCUMENT 09: COSMETIC SYSTEM


# COD:MW4 - Cosmetic System

## Custom Kill Effects (9 Types)

| ID | Effect Name | Visual Description |
|----|-------------|---------------------|
| 1 | Thunder | Screen shake and thunder sound |
| 2 | Explode | Explosion effect at victim position |
| 3 | Lightning | Dynamic light flash |
| 4 | Fire | Flame particles |
| 5 | Ice | Freeze effect |
| 6 | Blood | Blood spray effect |
| 7 | Gib | Gore effect |
| 8 | Electrocute | Electric shock effect |
| 9 | Shockwave | Radial blast effect |

## Custom Knives (5 Types)

| ID | Knife Name | Visual Model |
|----|------------|--------------|
| 1 | Katana | Japanese sword model |
| 2 | Machete | Large blade model |
| 3 | Axe | Combat axe model |
| 4 | Crossbow | Ranged weapon model |
| 5 | Bazooka | Rocket launcher model |

## Important Cosmetic Rules

- All cosmetic effects are PERMANENT once unlocked
- Effects are saved to database and persist across sessions
- Effects are purely visual - no gameplay advantage
- Duration limited to 0.2 seconds maximum
- No FPS drop on low-end PCs
- No view blocking
- No server lag on 32 players


## DOCUMENT 10: TECHNICAL SPECIFICATIONS


# COD:MW4 - Technical Specifications

## Platform Requirements

| Component | Requirement |
|-----------|-------------|
| AMXX Version | 1.9.0 (build 5242 or higher) |
| Compiler | Pawn 3.10 |
| Stack Size | #pragma dynamic 32768 |
| Database | SQLite (synchronous blocking only) |
| Minimum PC Spec | Pentium 4, 1GB RAM, Intel GMA 950 |

## Server Requirements

| Component | Recommendation |
|-----------|----------------|
| RAM | Minimum 2GB |
| CPU | 2+ cores |
| Network | Stable connection with minimal latency |
| Uptime | 95% or higher for production server |

## Asset Directory Structure

| Path | Contents |
|------|----------|
| models/CoDMod/ | 3D models for classes, items, effects |
| sound/CoDMod/ | Sound effects (40+ files) |
| sprites/CoDMod/ | Sprite effects for visual feedback |
| configs/codmod/ | Configuration and mission files |
| data/ | SQLite database file |
| logs/ | Admin action logs |

## Coding Standards

- 4-space indentation
- Braces on new line for functions
- Global variables grouped at file start
- Functions maximum 150 lines
- Clear comments for complex algorithms
- Full implementation (no stubs or placeholders)

## Prohibited Practices

| Practice | Reason |
|----------|--------|
| SQL_ThreadQuery | Must use synchronous blocking only |
| PreThink / PostThink | Use set_task instead |
| enum struct / methodmap | Not supported |
| // TODO / // FIXME / /* stub */ | Must have complete implementation |


## END OF PUBLIC DOCUMENTATION

**For more information, to contribute, or to join the community:**

- Discord Server: https://discord.gg/ZaGdCPGWzd
- GitHub Repository: https://github.com/amxxscripter412-hub/COD-MW4

---

*This documentation is for public consumption. Full source code is available to approved contributors only.*
