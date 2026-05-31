//=============================================================================
// COD:MW4 - Main Include File
// Version: 3.0.0
// Author: El
//=============================================================================
//  COD:MW4 - Complete Include File for AMX Mod X 1.9
//  =================================================
//
//  This file contains all necessary definitions, natives, forwards, and stocks
//  for the COD:MW4 modification. It is designed to be included in all class,
//  perk, shop, and cosmetic plugins.
//
// Note: This .inc just an outdated version, only coder got the latest version
//
//  DEPENDENCIES:
//    - AMX Mod X 1.9.0 or higher
//    - Required modules: cstrike, fakemeta, hamsandwich, sqlx
//
//  USAGE:
//    #include <cod>
//
//=============================================================================

#if defined _cod_included
    #endinput
#endif
#define _cod_included

//=============================================================================
// VERSION & BASIC CONSTANTS
//=============================================================================

/**
 * Plugin identification constants for consistent naming across all modules.
 */
#define PLUGIN         "COD:MW4"
#define VERSION        "3.0.0"
#define AUTHOR         "El"

/**
 * String length limits for various data types.
 * @note MAX_NAME - Standard player name length (32 chars)
 * @note MAX_SAFE_NAME - Double buffer for SQL escaping (64 chars)
 * @note MAX_DESC - Description text limit for items/classes/perks
 */
#define MAX_NAME        32
#define MAX_SAFE_NAME   64
#define MAX_DESC        256

/**
 * Maximum number of players supported by the game engine.
 * Used for array declarations and loops.
 */
#define MAX_PLAYERS     32

//=============================================================================
// BITFIELD OPERATION MACROS
//=============================================================================

/**
 * Macro to check if a specific bit is set in a bitfield.
 *
 * @param bit   Bit position to check (0-31)
 * @param field Bitfield variable to check against
 *
 * @return      1 if bit is set, 0 otherwise
 */
#define get_bit(%2,%1) (%1 & (1<<(%2&31)))

/**
 * Macro to set a specific bit in a bitfield.
 *
 * @param bit   Bit position to set (0-31)
 * @param field Bitfield variable to modify
 *
 * @noreturn
 */
#define set_bit(%2,%1) (%1 |= (1<<(%2&31)))

/**
 * Macro to clear a specific bit in a bitfield.
 *
 * @param bit   Bit position to clear (0-31)
 * @param field Bitfield variable to modify
 *
 * @noreturn
 */
#define rem_bit(%2,%1) (%1 &= ~(1 <<(%2&31)))

//=============================================================================
// RETURN VALUE CONSTANTS
//=============================================================================

/**
 * Return value indicating that execution should continue normally.
 */
#define COD_CONTINUE    0

/**
 * Return value indicating that an action was handled and should not propagate.
 */
#define COD_HANDLED     1

/**
 * Return value for Float functions to completely block an action.
 * Example: return COD_BLOCK in damage hooks to nullify damage.
 */
#define COD_BLOCK       -1.0

/**
 * Return value indicating that an operation should stop and not retry.
 */
#define COD_STOP        4

/**
 * Special speed value that completely freezes player movement.
 * Set player speed to this value to prevent any movement.
 */
#define COD_FREEZE      0.1

//=============================================================================
// PARAMETER TYPE CONSTANTS
//=============================================================================

/**
 * Special value to generate or select a random value.
 * Used for item values, class selection, etc.
 */
#define RANDOM          -3

/**
 * Special value indicating "all" or "full" - unlimited resources.
 * Used for teleports, unlimited ammo weapons, etc.
 */
#define FULL            -2

/**
 * No value / invalid / disabled state.
 */
#define NONE            -1

/**
 * Bonus type parameter for class-based bonuses.
 */
#define CLASS           0

/**
 * Bonus type parameter for item-based bonuses.
 */
#define ITEM            1

/**
 * Bonus type for additional/static bonuses (shop items, temporary effects).
 */
#define ADDITIONAL      2

/**
 * Bonus type for round-based bonuses (reset at round end).
 */
#define ROUND           3

/**
 * Bonus type that expires after dealing damage to an enemy.
 */
#define DAMAGE_GIVEN    4

/**
 * Bonus type that expires after taking damage from an enemy.
 */
#define DAMAGE_TAKEN    5

/**
 * Bonus type that expires after player death.
 */
#define DEATH           6

/**
 * Bonus type for tracking used resources (rockets, mines, etc. used this round).
 */
#define USED            7

/**
 * Bonus type for aggregate/all bonuses combined.
 */
#define ALL             8

//=============================================================================
// CLASS ACCESS LEVELS (TIERS)
//=============================================================================

/**
 * Free class - accessible to all players without restrictions.
 */
#define CLASS_ACCESS_FREE     0

/**
 * VIP class - requires VIP flag (ADMIN_LEVEL_H).
 */
#define CLASS_ACCESS_VIP      1

/**
 * Credit class - purchasable with credit currency.
 */
#define CLASS_ACCESS_CREDIT   2

/**
 * Custom class - special access, usually event rewards.
 */
#define CLASS_ACCESS_CUSTOM   3

//=============================================================================
// CURRENCY TYPE CONSTANTS
//=============================================================================

/**
 * Gold currency - common in-game currency earned from kills and quests.
 */
#define CURRENCY_GOLD        0

/**
 * CS Money - standard Counter-Strike money (displayed as honor in HUD).
 */
#define CURRENCY_CS_MONEY    1

/**
 * Credit - premium currency, hard to obtain, used for special items/classes.
 */
#define CURRENCY_CREDIT      2

/**
 * Fragment - currency for class mastery upgrades.
 */
#define CURRENCY_FRAGMENT    3

//=============================================================================
// SKILL TYPE CONSTANTS (Active Skills)
//=============================================================================

/**
 * Rocket skill - launches a projectile that explodes on contact.
 */
#define SKILL_ROCKET    1

/**
 * Mine skill - places a proximity mine that explodes when enemies approach.
 */
#define SKILL_MINE      2

/**
 * Dynamite skill - placeable explosive that can be remotely detonated.
 */
#define SKILL_DYNAMITE  3

/**
 * Medkit skill - healing item that can be placed for self or teammates.
 */
#define SKILL_MEDKIT    4

/**
 * Poison skill - places poison cloud that damages enemies over time.
 */
#define SKILL_POISON    5

/**
 * Thunder skill - lightning strike on aimed enemy.
 */
#define SKILL_THUNDER   6

/**
 * Teleport skill - instant teleport to aimed location.
 */
#define SKILL_TELEPORT  7

/**
 * Jetpack skill - temporary flight capability.
 */
#define SKILL_JETPACK   8

/**
 * Turret skill - deploys an automated turret.
 */
#define SKILL_TURRET    9

/**
 * Custom skill - plugin-defined skill type.
 */
#define SKILL_CUSTOM    10

//=============================================================================
// SYSTEM LIMIT CONSTANTS
//=============================================================================

/**
 * Maximum number of promotion paths per class (3: first, second, third).
 */
#define MAX_PROMO_PATHS       3

/**
 * Maximum mastery level (250 levels beyond normal max level).
 * Total background level = 250 + mastery.
 */
#define MAX_MASTERY_LEVEL     250

/**
 * Starting stat points at level 1.
 */
#define STAT_POINTS_START      4

/**
 * Stat points gained per level up.
 */
#define STAT_POINTS_PER_LEVEL  2

/**
 * Maximum points per individual attribute.
 */
#define STAT_MAX_PER_ATTRIBUTE 100

//=============================================================================
// FORTUNE CDR (Cooldown Reduction) CONSTANTS
//=============================================================================

/**
 * Maximum cooldown reduction percentage from Fortune attribute (20%).
 */
#define FORTUNE_CDR_MAX       20

/**
 * Cooldown reduction per Fortune point (0.2% per point).
 * At 100 Fortune = 20% reduction.
 */
#define FORTUNE_CDR_PER_POINT 0.002

//=============================================================================
// GAP PROTECTION - COMPLETE REDESIGN
//=============================================================================

/**
 * Minimum level gap to trigger underdog protection.
 * Players with level difference >= this value trigger stack mechanics.
 */
#define GAP_PROTECTION_LEVEL_THRESHOLD 80

/**
 * Maximum underdog stacks a player can accumulate.
 */
#define GAP_PROTECTION_MAX_STACK 5

/**
 * Stacks gained per death to a significantly higher level player.
 */
#define GAP_PROTECTION_STACK_GAIN_ON_DEATH 1

/**
 * Stacks lost when killing a significantly higher level player.
 */
#define GAP_PROTECTION_STACK_LOSS_ON_KILL 3

/**
 * Stacks lost per round if no kills on higher level players.
 */
#define GAP_PROTECTION_STACK_DECAY_PER_ROUND 1

/**
 * EXP multiplier when killing a higher level player with underdog stacks.
 * 2x EXP at max stacks.
 */
#define GAP_PROTECTION_EXP_MULTIPLIER 2.0

/**
 * Base chance (%) for bounty box spawn on kill with underdog stacks.
 * Each stack adds this percentage (max 250% = guaranteed at 2+ stacks).
 */
#define GAP_PROTECTION_BOUNTY_BOX_SPAWN_CHANCE 50

//=============================================================================
// KILL EFFECT IDs (Cosmetic)
//=============================================================================

/**
 * No kill effect - standard death animation.
 */
#define KILL_EFFECT_NONE         0

/**
 * Thunder Boss effect - dramatic lightning strike on death.
 */
#define KILL_EFFECT_THUNDER_BOSS 1

/**
 * Explode VIP effect - explosive death with fireball.
 */
#define KILL_EFFECT_EXPLODE_VIP  2

/**
 * Lightning effect - electrical discharge on death.
 */
#define KILL_EFFECT_LIGHTNING    3

/**
 * Fire effect - burning death animation.
 */
#define KILL_EFFECT_FIRE         4

/**
 * Ice effect - freezing death with shatter.
 */
#define KILL_EFFECT_ICE          5

/**
 * Blood effect - excessive blood spray.
 */
#define KILL_EFFECT_BLOOD        6

/**
 * Gib effect - body explodes into pieces.
 */
#define KILL_EFFECT_GIB          7

/**
 * Electrocute effect - sustained electrical arcing.
 */
#define KILL_EFFECT_ELECTROCUTE  8

/**
 * Shockwave effect - radial energy wave.
 */
#define KILL_EFFECT_SHOCKWAVE    9

//=============================================================================
// CUSTOM KNIFE IDs (Cosmetic)
//=============================================================================

/**
 * Default knife model.
 */
#define CUSTOM_KNIFE_DEFAULT     0

/**
 * Katana - Japanese long sword.
 */
#define CUSTOM_KNIFE_KATANA      1

/**
 * Machete - large chopping blade.
 */
#define CUSTOM_KNIFE_MACHETE     2

/**
 * Axe - combat axe.
 */
#define CUSTOM_KNIFE_AXE         3

/**
 * Crossbow - ranged knife replacement.
 */
#define CUSTOM_KNIFE_CROSSBOW    4

/**
 * Bazooka - rocket launcher knife skin.
 */
#define CUSTOM_KNIFE_BAZOOKA     5

//=============================================================================
// STREAK TYPES (5 Jenis)
//=============================================================================

/**
 * Daily login streak.
 */
#define STREAK_DAILY    0

/**
 * Weekly play streak.
 */
#define STREAK_WEEKLY   1

/**
 * Kill streak (consecutive kills without dying).
 */
#define STREAK_KILL     2

/**
 * Round win streak.
 */
#define STREAK_ROUND    3

/**
 * Quest completion streak.
 */
#define STREAK_QUEST    4

//=============================================================================
// RESET & LEADERBOARD CONSTANTS
//=============================================================================

/**
 * Reset interval in days (60 days = 2 months).
 */
#define RESET_DAYS_INTERVAL    60

/**
 * Leaderboard rank 1 credit reward.
 */
#define LEADERBOARD_REWARD_TOP1_CREDIT   15

/**
 * Leaderboard rank 1 gold reward.
 */
#define LEADERBOARD_REWARD_TOP1_GOLD     1500

/**
 * Leaderboard rank 2 credit reward.
 */
#define LEADERBOARD_REWARD_TOP2_CREDIT   14

/**
 * Leaderboard rank 2 gold reward.
 */
#define LEADERBOARD_REWARD_TOP2_GOLD     1400

/**
 * Leaderboard rank 3 credit reward.
 */
#define LEADERBOARD_REWARD_TOP3_CREDIT   13

/**
 * Leaderboard rank 3 gold reward.
 */
#define LEADERBOARD_REWARD_TOP3_GOLD     1300

/**
 * Leaderboard rank 4 credit reward.
 */
#define LEADERBOARD_REWARD_TOP4_CREDIT   12

/**
 * Leaderboard rank 4 gold reward.
 */
#define LEADERBOARD_REWARD_TOP4_GOLD     1200

/**
 * Leaderboard rank 5 credit reward.
 */
#define LEADERBOARD_REWARD_TOP5_CREDIT   11

/**
 * Leaderboard rank 5 gold reward.
 */
#define LEADERBOARD_REWARD_TOP5_GOLD     1100

/**
 * Leaderboard rank 6 credit reward.
 */
#define LEADERBOARD_REWARD_TOP6_CREDIT   10

/**
 * Leaderboard rank 6 gold reward.
 */
#define LEADERBOARD_REWARD_TOP6_GOLD     1000

/**
 * Leaderboard rank 7 credit reward.
 */
#define LEADERBOARD_REWARD_TOP7_CREDIT   9

/**
 * Leaderboard rank 7 gold reward.
 */
#define LEADERBOARD_REWARD_TOP7_GOLD     900

/**
 * Leaderboard rank 8 credit reward.
 */
#define LEADERBOARD_REWARD_TOP8_CREDIT   8

/**
 * Leaderboard rank 8 gold reward.
 */
#define LEADERBOARD_REWARD_TOP8_GOLD     800

/**
 * Leaderboard rank 9 credit reward.
 */
#define LEADERBOARD_REWARD_TOP9_CREDIT   7

/**
 * Leaderboard rank 9 gold reward.
 */
#define LEADERBOARD_REWARD_TOP9_GOLD     700

/**
 * Leaderboard rank 10 credit reward.
 */
#define LEADERBOARD_REWARD_TOP10_CREDIT  6

/**
 * Leaderboard rank 10 gold reward.
 */
#define LEADERBOARD_REWARD_TOP10_GOLD    600

/**
 * Leaderboard rank 11 credit reward.
 */
#define LEADERBOARD_REWARD_TOP11_CREDIT  5

/**
 * Leaderboard rank 11 gold reward.
 */
#define LEADERBOARD_REWARD_TOP11_GOLD    500

/**
 * Leaderboard rank 12 credit reward.
 */
#define LEADERBOARD_REWARD_TOP12_CREDIT  4

/**
 * Leaderboard rank 12 gold reward.
 */
#define LEADERBOARD_REWARD_TOP12_GOLD    400

/**
 * Leaderboard rank 13 credit reward.
 */
#define LEADERBOARD_REWARD_TOP13_CREDIT  3

/**
 * Leaderboard rank 13 gold reward.
 */
#define LEADERBOARD_REWARD_TOP13_GOLD    300

/**
 * Leaderboard rank 14 credit reward.
 */
#define LEADERBOARD_REWARD_TOP14_CREDIT  2

/**
 * Leaderboard rank 14 gold reward.
 */
#define LEADERBOARD_REWARD_TOP14_GOLD    200

/**
 * Leaderboard rank 15 credit reward.
 */
#define LEADERBOARD_REWARD_TOP15_CREDIT  1

/**
 * Leaderboard rank 15 gold reward.
 */
#define LEADERBOARD_REWARD_TOP15_GOLD    100

//=============================================================================
// DAMAGE FLAGS (Extended from standard DMG_*)
//=============================================================================

/**
 * Bullet damage flag.
 */
#define DMG_BULLET      (1<<1)

/**
 * Burn/fire damage flag.
 */
#define DMG_BURN        (1<<3)

/**
 * Freeze damage flag.
 */
#define DMG_FREEZE      (1<<4)

/**
 * Fall damage flag.
 */
#define DMG_FALL        (1<<5)

/**
 * Nerve gas/poison damage flag.
 */
#define DMG_NERVEGAS    (1<<16)

/**
 * HE grenade damage flag (Counter-Strike specific).
 */
#define DMG_HEGRENADE   (1<<24)

/**
 * Dynamite skill damage flag (COD custom).
 */
#define DMG_DYNAMITE    (1<<25)

/**
 * Mine skill damage flag (COD custom).
 */
#define DMG_MINE        (1<<26)

/**
 * Rocket skill damage flag (COD custom).
 */
#define DMG_ROCKET      (1<<27)

/**
 * Thunder skill damage flag (COD custom).
 */
#define DMG_THUNDER     (1<<28)

/**
 * Kill command damage flag (instant kill from cod_kill_player).
 */
#define DMG_KILL        (1<<29)

/**
 * Repeating damage flag (for DOT effects like fire/poison).
 */
#define DMG_REPEAT      (1<<30)

/**
 * COD skill damage flag (always set for custom damage).
 */
#define DMG_CODSKILL    (1<<31)

//=============================================================================
// HUD DISPLAY TYPES
//=============================================================================

/**
 * Standard HUD message (channel-based, multiple channels available).
 */
#define TYPE_HUD    0

/**
 * Director HUD message (stack-based, up to 8 simultaneous messages).
 */
#define TYPE_DHUD   1

//=============================================================================
// SOUND INDEX CONSTANTS (40 Suara)
//=============================================================================

/**
 * Sound index: Menu selection sound.
 */
#define SOUND_SELECT            0

/**
 * Sound index: Menu exit/close sound.
 */
#define SOUND_EXIT              1

/**
 * Sound index: Round start sound (CT).
 */
#define SOUND_START             2

/**
 * Sound index: Round start sound (T).
 */
#define SOUND_START2            3

/**
 * Sound index: Level up sound 1.
 */
#define SOUND_LVLUP             4

/**
 * Sound index: Level up sound 2.
 */
#define SOUND_LVLUP2            5

/**
 * Sound index: Level up sound 3.
 */
#define SOUND_LVLUP3            6

/**
 * Sound index: Skill deploy sound.
 */
#define SOUND_DEPLOY            7

/**
 * Sound index: Skill activation sound.
 */
#define SOUND_ACTIVATE          8

/**
 * Sound index: Skill charging sound.
 */
#define SOUND_CHARGE            9

/**
 * Sound index: Item pickup sound.
 */
#define SOUND_PICKUP            10

/**
 * Sound index: Thunder skill sound.
 */
#define SOUND_THUNDER           11

/**
 * Sound index: "One" voice for last man standing.
 */
#define SOUND_ONE               12

/**
 * Sound index: "Last" voice for last man standing.
 */
#define SOUND_LAST              13

/**
 * Sound index: "The force" voice for duel.
 */
#define SOUND_FORCE             14

/**
 * Sound index: Humiliation sound (knife kill).
 */
#define SOUND_HUMILIATION       15

/**
 * Sound index: Bomb-related sound.
 */
#define SOUND_BOMB              16

/**
 * Sound index: Applause sound.
 */
#define SOUND_APPLAUSE          17

/**
 * Sound index: Laugh sound.
 */
#define SOUND_LAUGH             18

/**
 * Sound index: Bounty activation sound.
 */
#define SOUND_BOUNTY            19

/**
 * Sound index: Bounty box spawn sound.
 */
#define SOUND_BOUNTY_BOX_SPAWN  20

/**
 * Sound index: Bounty box pickup sound.
 */
#define SOUND_BOUNTY_BOX_TAKE   21

/**
 * Sound index: Turret firing sound.
 */
#define SOUND_TURRET_FIRE       22

/**
 * Sound index: Turret deploy sound.
 */
#define SOUND_TURRET_DEPLOY     23

/**
 * Sound index: Turret explosion sound.
 */
#define SOUND_TURRET_EXPLODE    24

/**
 * Sound index: Rocket launch sound.
 */
#define SOUND_ROCKET_LAUNCH     25

/**
 * Sound index: Teleport sound.
 */
#define SOUND_TELEPORT          26

/**
 * Sound index: Daily streak milestone sound.
 */
#define SOUND_STREAK_DAILY      27

/**
 * Sound index: Weekly streak milestone sound.
 */
#define SOUND_STREAK_WEEKLY     28

/**
 * Sound index: Kill streak milestone sound.
 */
#define SOUND_STREAK_KILL       29

/**
 * Sound index: Round streak milestone sound.
 */
#define SOUND_STREAK_ROUND      30

/**
 * Sound index: Quest streak milestone sound.
 */
#define SOUND_STREAK_QUEST      31

/**
 * Sound index: Daily bonus reward sound.
 */
#define SOUND_DAILY_BONUS       32

/**
 * Sound index: Achievement unlock sound.
 */
#define SOUND_ACHIEVEMENT       33

/**
 * Sound index: Loot box open sound.
 */
#define SOUND_BOX_OPEN          34

/**
 * Sound index: Loot box spin sound.
 */
#define SOUND_BOX_SPIN          35

/**
 * Sound index: Item get sound.
 */
#define SOUND_ITEM_GET          36

/**
 * Sound index: Jackpot sound (legendary item).
 */
#define SOUND_JACKPOT           37

/**
 * Sound index: Near miss sound (2 legendaries in box spin).
 */
#define SOUND_NEAR_MISS         38

/**
 * Sound index: Box stolen sound.
 */
#define SOUND_BOX_STOLEN        39

/**
 * Array of all sound file paths (40 sounds total).
 * Paths are relative to the 'sound' folder.
 * All sounds must be precached in plugin_precache().
 */
new const codSounds[SOUND_BOX_STOLEN + 1][] = {
    "CoDMod/select.wav",            // 0
    "CoDMod/close.wav",             // 1
    "CoDMod/start.wav",             // 2
    "CoDMod/start2.wav",            // 3
    "CoDMod/levelup.wav",           // 4
    "CoDMod/levelup2.wav",          // 5
    "CoDMod/levelup3.wav",          // 6
    "CoDMod/deploy.wav",            // 7
    "CoDMod/activate.wav",          // 8
    "CoDMod/charge.wav",            // 9
    "CoDMod/pickup.wav",            // 10
    "CoDMod/thunder.wav",           // 11
    "CoDMod/one.wav",               // 12
    "CoDMod/last.wav",              // 13
    "CoDMod/force.wav",             // 14
    "CoDMod/humiliation.wav",       // 15
    "CoDMod/bomb.wav",              // 16
    "CoDMod/applause.wav",          // 17
    "CoDMod/laugh.wav",             // 18
    "CoDMod/bounty.wav",            // 19
    "CoDMod/bounty_box_spawn.wav",  // 20
    "CoDMod/bounty_box_take.wav",   // 21
    "CoDMod/turret_fire.wav",       // 22
    "CoDMod/turret_deploy.wav",     // 23
    "CoDMod/turret_explode.wav",    // 24
    "CoDMod/rocket_launch.wav",     // 25
    "CoDMod/teleport.wav",          // 26
    "CoDMod/streak_daily.wav",      // 27
    "CoDMod/streak_weekly.wav",     // 28
    "CoDMod/streak_kill.wav",       // 29
    "CoDMod/streak_round.wav",      // 30
    "CoDMod/streak_quest.wav",      // 31
    "CoDMod/daily_bonus.wav",       // 32
    "CoDMod/achievement.wav",       // 33
    "CoDMod/box_open.wav",          // 34
    "CoDMod/box_spin.wav",          // 35
    "CoDMod/item_get.wav",          // 36
    "CoDMod/jackpot.wav",           // 37
    "CoDMod/near_miss.wav",         // 38
    "CoDMod/box_stolen.wav"         // 39
};

//=============================================================================
// PLAYER DATA STRUCTURE (ENUM)
//=============================================================================

/**
 * Complete player data structure containing all persistent and temporary stats.
 * This enum is used with g_playerData[MAX_PLAYERS+1][CodPlayerData] array.
 *
 * @note PLAYER_NAME and PLAYER_SAFE_NAME are arrays, not integers.
 * @note All other fields are integer cells.
 */
enum CodPlayerData {
    // Class and Level System
    PLAYER_CLASS,               ///< Current class index (0 = no class)
    PLAYER_LEVEL,               ///< Current visual level (1-250)
    PLAYER_EXP,                 ///< Current experience points
    PLAYER_GAINED_EXP,          ///< Unsynced EXP (for batch saving)
    
    // Core Attributes (0-100 max each)
    PLAYER_INT,                 ///< Intelligence (damage multiplier, IK chance)
    PLAYER_STR,                 ///< Strength (damage reduction, counter IK)
    PLAYER_STAM,                ///< Stamina (movement speed bonus)
    PLAYER_COND,                ///< Condition (health bonus)
    PLAYER_FOR,                 ///< Fortune (RNG bonus, CDR)
    PLAYER_POINTS,              ///< Unassigned stat points
    
    // Currency System (4 types)
    PLAYER_GOLD,                ///< Gold currency (common)
    PLAYER_CS_MONEY,            ///< CS Money (displayed as honor)
    PLAYER_CREDIT,              ///< Credit (premium)
    PLAYER_FRAGMENTS,           ///< Fragment (mastery currency)
    
    // Equipment & Cosmetics
    PLAYER_PERK,                ///< Active perk ID (0 = none)
    PLAYER_PATH,                ///< Promotion path (1-3)
    PLAYER_MASTERY,             ///< Mastery level (0-250)
    PLAYER_KILL_EFFECT,         ///< Selected kill effect ID (0-9)
    PLAYER_UNLOCKED_EFFECTS,    ///< Bitfield of unlocked effects
    PLAYER_CUSTOM_KNIFE,        ///< Selected custom knife ID (0-5)
    PLAYER_UNLOCKED_KNIVES,     ///< Bitfield of unlocked knives
    
    // Streak System (5 types)
    PLAYER_KS,                  ///< Current kill streak
    PLAYER_ROUND_STREAK,        ///< Round win streak
    PLAYER_DAILY_STREAK,        ///< Daily login streak (1-8, resets to 1)
    PLAYER_WEEKLY_STREAK,       ///< Weekly play streak
    PLAYER_QUEST_STREAK,        ///< Quest completion streak
    
    // Bounty System
    PLAYER_BOUNTY_ACTIVE,       ///< Whether player has active bounty
    PLAYER_BOUNTY_KS,           ///< Kill streak when bounty activated
    
    // Kulawangsa Shield
    PLAYER_SHIELD_ACTIVE,       ///< Whether shield is active this round
    PLAYER_SHIELD_USED,         ///< Whether shield was used this round
    
    // Achievement System
    PLAYER_ACHV_FLAGS_1,        ///< Achievements 0-31 bitfield
    PLAYER_ACHV_FLAGS_2,        ///< Achievements 32-63 bitfield
    PLAYER_LAST_ACHIEVEMENT_ID, ///< Last unlocked achievement ID
    PLAYER_LAST_ACHIEVEMENT_TIME, ///< Timestamp of last achievement
    
    // Quest System (3 active quests)
    PLAYER_QUEST_1,             ///< Quest ID for slot 1
    PLAYER_QUEST_2,             ///< Quest ID for slot 2
    PLAYER_QUEST_3,             ///< Quest ID for slot 3
    PLAYER_QUEST_PROG_1,        ///< Progress for slot 1
    PLAYER_QUEST_PROG_2,        ///< Progress for slot 2
    PLAYER_QUEST_PROG_3,        ///< Progress for slot 3
    
    // Statistics & Time
    PLAYER_TOTAL_EXP_EARNED,    ///< Lifetime EXP earned (for ranking)
    PLAYER_LAST_RESET_TIME,     ///< Last reset timestamp (for 2-month cycle)
    PLAYER_DAILY_LAST_LOGIN,    ///< Last login timestamp (Unix)
    PLAYER_WEEKLY_LAST_PLAY,    ///< Last week timestamp
    PLAYER_QUEST_STREAK_FAIL,   ///< Whether quest streak failed today
    PLAYER_LAST_ROUND_WIN,      ///< Last round win timestamp (for streak)
    PLAYER_KS_BONUS_PCT,        ///< Current kill streak bonus percentage
    
    // Name Storage (arrays)
    PLAYER_NAME[MAX_NAME],      ///< Player name (unescaped)
    PLAYER_SAFE_NAME[MAX_SAFE_NAME] ///< SQL-escaped player name
};

//=============================================================================
// NATIVE FUNCTIONS - Core System
//=============================================================================

/**
 * Opens the main COD:MW4 menu for the player.
 * This menu contains all game options including class selection, shop, stats, etc.
 *
 * @param id    Player index
 *
 * @noreturn
 * @error       If the player index is invalid or not connected, an error is thrown.
 */
native cod_open_main_menu(id);

/**
 * Starts the scrolling HUD message display for a player.
 * The scrolling message is displayed at the bottom of the screen.
 *
 * @param id    Player index
 *
 * @noreturn
 * @error       If the player index is invalid or not connected, an error is thrown.
 */
native cod_start_scrolling_hud(id);

/**
 * Binds the 'M' key to open the main menu for the player.
 * Also binds 'V' as a fallback key.
 *
 * @param id    Player index
 *
 * @noreturn
 * @error       If the player index is invalid or not connected, an error is thrown.
 */
native cod_bind_menu_key(id);

//=============================================================================
// NATIVE FUNCTIONS - Streak System
//=============================================================================

/**
 * Checks and updates the player's daily login streak.
 * Automatically called on player connection.
 * Streak resets to 1 if more than one day missed.
 *
 * @param id    Player index
 *
 * @noreturn
 * @error       If the player index is invalid or not connected, an error is thrown.
 */
native cod_check_daily_streak(id);

/**
 * Checks and updates the player's weekly play streak.
 * Automatically called on player connection.
 *
 * @param id    Player index
 *
 * @noreturn
 * @error       If the player index is invalid or not connected, an error is thrown.
 */
native cod_check_weekly_streak(id);

/**
 * Checks and updates the player's quest completion streak.
 *
 * @param id    Player index
 *
 * @noreturn
 * @error       If the player index is invalid or not connected, an error is thrown.
 */
native cod_check_quest_streak(id);

/**
 * Returns the total EXP bonus percentage from all active streaks.
 *
 * @param id    Player index
 *
 * @return      EXP bonus as multiplier (1.0 = 100%, 1.2 = 120% EXP)
 * @error       If the player index is invalid or not connected, an error is thrown.
 */
native Float:cod_get_streak_exp_bonus(id);

//=============================================================================
// NATIVE FUNCTIONS - Level Up & Achievement Effects
//=============================================================================

/**
 * Triggers level up visual effects (screen shake, fade, sound, HUD message).
 *
 * @param id            Player index
 * @param old_level     Previous level before gain
 * @param new_level     New level after gain
 *
 * @noreturn
 * @error               If player index is invalid or not connected, an error is thrown.
 */
native cod_level_up_effects(id, old_level, new_level);

/**
 * Checks all achievements and displays near-completion warnings (90%+ progress).
 * Shows HUD message with list of achievements close to unlocking.
 *
 * @param id    Player index
 *
 * @noreturn
 * @error       If player index is invalid or not connected, an error is thrown.
 */
native cod_check_achievement_near_completion(id);

/**
 * Displays the player's most recently unlocked achievement on HUD.
 * Used to show achievement popup when a new achievement is unlocked.
 *
 * @param id    Player index
 *
 * @noreturn
 * @error       If player index is invalid or not connected, an error is thrown.
 */
native cod_show_last_achievement_hud(id);

//=============================================================================
// NATIVE FUNCTIONS - Sound System
//=============================================================================

/**
 * Plays a sound to a specific player.
 *
 * @param id            Player index
 * @param sound_index   Sound index from codSounds array (SOUND_* constants)
 *
 * @noreturn
 * @error               If player index is invalid or sound_index out of range.
 */
native cod_play_sound(id, sound_index);

/**
 * Plays a sound to all connected players.
 *
 * @param sound_index   Sound index from codSounds array (SOUND_* constants)
 *
 * @noreturn
 * @error               If sound_index is out of range.
 */
native cod_play_sound_to_all(sound_index);

//=============================================================================
// NATIVE FUNCTIONS - Loot Box System
//=============================================================================

/**
 * Opens a loot box with visual spin effect and reward distribution.
 * Shows 3 spinning results and awards the final reward.
 *
 * @param id        Player index opening the box
 * @param box_ent   Box entity index
 * @param box_type  Box type (0 = legacy, 1 = bounty, 2 = momentum)
 *
 * @noreturn
 * @error           If player index is invalid or box entity invalid.
 */
native cod_open_box_with_effect(id, box_ent, box_type);

//=============================================================================
// NATIVE FUNCTIONS - Equipment & Spawn Bonuses
//=============================================================================

/**
 * Gives the player full armor (100 kevlar + helmet) on spawn.
 * Also refills armor if damaged.
 *
 * @param id    Player index
 *
 * @noreturn
 * @error       If player index is invalid or not connected, an error is thrown.
 */
native cod_give_full_armor(id);

/**
 * Enables unlimited backpack ammo for the player.
 * Ammo in reserve never decreases when shooting.
 *
 * @param id    Player index
 *
 * @noreturn
 * @error       If player index is invalid or not connected, an error is thrown.
 */
native cod_enable_unlimited_bp_ammo(id);

//=============================================================================
// NATIVE FUNCTIONS - Leaderboard & Reset System
//=============================================================================

/**
 * Gives leaderboard rewards to a player based on their rank.
 * Rewards include Credit and Gold.
 *
 * @param rank          Player's rank position (1-15)
 * @param player_auth   Player's SteamID/auth ID
 * @param player_name   Player's name for logging
 *
 * @noreturn
 */
native cod_give_leaderboard_reward(rank, player_auth[], player_name[]);

/**
 * Processes the 2-month reset cycle and distributes leaderboard rewards.
 * Called automatically at map start or via admin command.
 * Checks if 60 days have passed since last reset.
 *
 * @noreturn
 */
native cod_process_reset_and_rewards();

//=============================================================================
// NATIVE FUNCTIONS - Gap Protection System
//=============================================================================

/**
 * Checks if there is a significant level gap between two players.
 * Gap is significant if difference >= GAP_PROTECTION_LEVEL_THRESHOLD.
 *
 * @param id1   First player index
 * @param id2   Second player index
 *
 * @return      1 if gap is significant, 0 otherwise
 * @error       If either player index is invalid or not connected.
 */
native cod_is_level_gap_significant(id1, id2);

/**
 * Gets the current underdog stack count for a player.
 * Stacks increase when dying to higher level players.
 * Stacks decrease when killing higher level players.
 *
 * @param id    Player index
 *
 * @return      Current stack count (0-5)
 * @error       If player index is invalid or not connected.
 */
native cod_get_underdog_stack(id);

/**
 * Gets the damage multiplier against higher level players.
 * Formula: 1.0 + (stack * 0.03) -> max 1.15 at 5 stacks.
 *
 * @param attacker  Attacker index (lower level)
 * @param victim    Victim index (higher level)
 *
 * @return          Damage multiplier as Float
 * @error           If either player index is invalid or not connected.
 */
native Float:cod_get_underdog_damage_multiplier(attacker, victim);

/**
 * Gets the damage reduction multiplier against higher level attackers.
 * Formula: 1.0 - (stack * 0.03) -> min 0.85 at 5 stacks.
 *
 * @param victim    Victim index (lower level)
 * @param attacker  Attacker index (higher level)
 *
 * @return          Damage reduction multiplier as Float
 * @error           If either player index is invalid or not connected.
 */
native Float:cod_get_underdog_damage_reduction(victim, attacker);

/**
 * Gets the speed boost duration after spawn (only active when stacks >= 3).
 *
 * @param id    Player index
 *
 * @return      Speed boost duration in seconds (0 if stacks < 3)
 * @error       If player index is invalid or not connected.
 */
native Float:cod_get_underdog_speed_boost_duration(id);

/**
 * Gets the movement speed multiplier from underdog stacks (stack >= 3).
 * Formula: 1.0 + (stack >= 3 ? 0.15 : 0.0) -> max 1.15.
 *
 * @param id    Player index
 *
 * @return      Speed multiplier as Float
 * @error       If player index is invalid or not connected.
 */
native Float:cod_get_underdog_speed_multiplier(id);

/**
 * Checks if player has armor bypass from underdog stacks (stack == 5).
 * When active, ignores 100% of enemy STR and armor.
 *
 * @param id    Player index
 *
 * @return      1 if armor bypass active, 0 otherwise
 * @error       If player index is invalid or not connected.
 */
native cod_has_underdog_armor_bypass(id);

/**
 * Gets the EXP multiplier for killing higher level players.
 * Formula: 1.0 + (stack * 0.2) -> max 2.0 at 5 stacks.
 *
 * @param attacker  Attacker index (lower level)
 * @param victim    Victim index (higher level)
 *
 * @return          EXP multiplier as Float
 * @error           If either player index is invalid or not connected.
 */
native Float:cod_get_underdog_exp_multiplier(attacker, victim);

/**
 * Adds an underdog stack to a player (max 5).
 * Only called when player dies to a significantly higher level player.
 *
 * @param id    Player index
 *
 * @noreturn
 * @error       If player index is invalid or not connected.
 */
native cod_add_underdog_stack(id);

/**
 * Removes underdog stacks from a player.
 * Called when player kills a significantly higher level player.
 *
 * @param id        Player index
 * @param amount    Amount of stacks to remove (default: GAP_PROTECTION_STACK_LOSS_ON_KILL)
 *
 * @noreturn
 * @error           If player index is invalid or not connected.
 */
native cod_remove_underdog_stack(id, amount = GAP_PROTECTION_STACK_LOSS_ON_KILL);

/**
 * Decays underdog stacks by 1 for all players.
 * Called at the end of each round.
 *
 * @noreturn
 */
native cod_decay_underdog_stacks();

/**
 * Resets all underdog stacks (called on map change or data reset).
 *
 * @noreturn
 */
native cod_reset_underdog_stacks();

/**
 * Checks if a bounty box should spawn on kill based on underdog stacks.
 * Bounty box spawn chance: stack * GAP_PROTECTION_BOUNTY_BOX_SPAWN_CHANCE.
 * Max 250% (guaranteed at 2+ stacks).
 *
 * @param attacker  Attacker index (lower level)
 *
 * @return          1 if box should spawn, 0 otherwise
 * @error           If player index is invalid or not connected.
 */
native cod_should_spawn_bounty_box(attacker);

/**
 * Checks gap protection danger indicator for aiming at higher level player.
 * Shows "DANGER!" warning on crosshair.
 *
 * @param id      Player index doing the aiming
 * @param target  Target player index being aimed at
 *
 * @return        1 if danger should be shown, 0 otherwise
 * @error         If either player index is invalid or not connected.
 */
native cod_check_gap_protection_danger(id, target);

/**
 * Checks if a bounty box should spawn on death (legacy bounty system).
 *
 * @param victim  Victim player index
 * @param killer  Killer player index
 *
 * @return        True if bounty box should spawn
 */
native bool:cod_should_spawn_bounty_on_death(victim, killer);

//=============================================================================
// NATIVE FUNCTIONS - Cosmetic System
//=============================================================================

/**
 * Gets the player's selected kill effect ID.
 *
 * @param id    Player index
 *
 * @return      Effect ID (0 = none, 1-9 = various effects)
 * @error       If player index is invalid or not connected.
 */
native cod_get_user_kill_effect(id);

/**
 * Sets the player's selected kill effect.
 *
 * @param id            Player index
 * @param effect_id     Effect ID (0-9, must be unlocked)
 *
 * @noreturn
 * @error               If player index is invalid or effect_id out of range.
 */
native cod_set_user_kill_effect(id, effect_id);

/**
 * Checks if a player has unlocked a specific kill effect.
 *
 * @param id            Player index
 * @param effect_id     Effect ID to check
 *
 * @return              1 if unlocked, 0 otherwise
 * @error               If player index is invalid or effect_id out of range.
 */
native cod_has_unlocked_effect(id, effect_id);

/**
 * Unlocks a kill effect for a player.
 * Permanent unlock - saved to database.
 *
 * @param id            Player index
 * @param effect_id     Effect ID to unlock
 *
 * @noreturn
 * @error               If player index is invalid or effect_id out of range.
 */
native cod_unlock_effect(id, effect_id);

/**
 * Gets the player's selected custom knife ID.
 *
 * @param id    Player index
 *
 * @return      Knife ID (0 = default, 1-5 = custom knives)
 * @error       If player index is invalid or not connected.
 */
native cod_get_user_custom_knife(id);

/**
 * Sets the player's selected custom knife.
 *
 * @param id            Player index
 * @param knife_id      Knife ID (0-5, must be unlocked)
 *
 * @noreturn
 * @error               If player index is invalid or knife_id out of range.
 */
native cod_set_user_custom_knife(id, knife_id);

/**
 * Checks if a player has unlocked a specific custom knife.
 *
 * @param id            Player index
 * @param knife_id      Knife ID to check
 *
 * @return              1 if unlocked, 0 otherwise
 * @error               If player index is invalid or knife_id out of range.
 */
native cod_has_unlocked_knife(id, knife_id);

/**
 * Unlocks a custom knife for a player.
 * Permanent unlock - saved to database.
 *
 * @param id            Player index
 * @param knife_id      Knife ID to unlock
 *
 * @noreturn
 * @error               If player index is invalid or knife_id out of range.
 */
native cod_unlock_knife(id, knife_id);

/**
 * Triggers a kill effect visual at the victim's position.
 *
 * @param killer        Killer player index
 * @param victim        Victim player index (for effect positioning)
 * @param effect_id     Effect ID to trigger
 * @param victim_origin Victim's origin coordinates
 *
 * @noreturn
 * @error               If player index is invalid or effect_id out of range.
 */
native cod_trigger_kill_effect(killer, victim, effect_id, Float:victim_origin[3]);

//=============================================================================
// NATIVE FUNCTIONS - Class System (Legacy compatibility + extensions)
//=============================================================================

/**
 * Opens the main menu for the player (alias for cod_open_main_menu).
 *
 * @param id    Player index
 *
 * @noreturn
 */
stock cod_main_menu(id) {
    cod_open_main_menu(id);
}

//=============================================================================
// FORWARD FUNCTIONS - Global Events
//=============================================================================

/**
 * Called when a bounty target is killed.
 *
 * @param killer    Killer index
 * @param victim    Bounty target index
 *
 * @noreturn
 */
forward cod_bounty_killed(killer, victim);

/**
 * Called when a bounty box is taken by a player.
 *
 * @param player        Player index who took the box
 * @param box_ent       Box entity index
 * @param reward_type   Type of reward (0 = gold, 1 = exp, 2 = credit, 3 = fragment)
 *
 * @noreturn
 */
forward cod_bounty_box_taken(player, box_ent, reward_type);

/**
 * Called when a quest is completed.
 *
 * @param id        Player index
 * @param quest_id  Completed quest ID
 *
 * @noreturn
 */
forward cod_quest_completed(id, quest_id);

/**
 * Called when a player gains mastery level.
 *
 * @param id            Player index
 * @param class_id      Class index that gained mastery
 * @param old_mastery   Previous mastery level
 * @param new_mastery   New mastery level
 *
 * @noreturn
 */
forward cod_mastery_gained(id, class_id, old_mastery, new_mastery);

/**
 * Called when a perk is enabled for a player.
 *
 * @param id        Player index
 * @param perk_id   Perk ID that was enabled
 *
 * @noreturn
 */
forward cod_perk_enabled(id, perk_id);

/**
 * Called when a perk is disabled for a player.
 *
 * @param id        Player index
 * @param perk_id   Perk ID that was disabled
 *
 * @noreturn
 */
forward cod_perk_disabled(id, perk_id);

/**
 * Called when a player with a perk makes a kill.
 *
 * @param killer    Killer index
 * @param victim    Victim index
 * @param perk_id   Perk ID of the killer
 * @param weapon    Weapon used for the kill
 * @param headshot  Whether kill was a headshot
 *
 * @noreturn
 */
forward cod_perk_kill(killer, victim, perk_id, weapon, headshot);

/**
 * Called when a turret is destroyed.
 *
 * @param owner         Turret owner index
 * @param turret_ent    Turret entity index
 *
 * @noreturn
 */
forward cod_turret_destroyed(owner, turret_ent);

/**
 * Called when an achievement is unlocked.
 *
 * @param id        Player index
 * @param achv_id   Achievement ID that was unlocked
 *
 * @noreturn
 */
forward cod_achievement_unlocked(id, achv_id);

/**
 * Called when a promotion path is chosen.
 *
 * @param id        Player index
 * @param class_id  Class index for promotion
 * @param path_id   Promotion path ID (1-3)
 *
 * @noreturn
 */
forward cod_promotion_chosen(id, class_id, path_id);

/**
 * Called when data reset occurs.
 *
 * @param id    Player index affected by reset
 *
 * @noreturn
 */
forward cod_reset_occurred(id);

/**
 * Called when a streak milestone is reached.
 *
 * @param id            Player index
 * @param streak_type   Streak type (STREAK_* constant)
 * @param streak_value  Current streak value
 * @param reward_xp     EXP reward amount
 * @param reward_gold   Gold reward amount
 *
 * @noreturn
 */
forward cod_streak_milestone(id, streak_type, streak_value, reward_xp, reward_gold);

/**
 * Called when daily streak reward is claimed.
 *
 * @param id            Player index
 * @param streak_day    Current streak day (1-8)
 * @param reward_xp     EXP reward amount
 * @param reward_gold   Gold reward amount
 *
 * @noreturn
 */
forward cod_daily_streak_claimed(id, streak_day, reward_xp, reward_gold);

/**
 * Called when weekly streak reward is claimed.
 *
 * @param id            Player index
 * @param streak_day    Current streak week
 * @param reward_xp     EXP reward amount
 * @param reward_gold   Gold reward amount
 *
 * @noreturn
 */
forward cod_weekly_streak_claimed(id, streak_day, reward_xp, reward_gold);

/**
 * Called when quest streak milestone is reached.
 *
 * @param id            Player index
 * @param streak_value  Current streak value
 * @param reward_xp     EXP reward amount
 *
 * @noreturn
 */
forward cod_quest_streak_milestone(id, streak_value, reward_xp);

/**
 * Called when a loot box is spun (results shown).
 *
 * @param id        Player index
 * @param box_ent   Box entity index
 * @param results   Array of 3 spin results
 *
 * @noreturn
 */
forward cod_box_spun(id, box_ent, results[3]);

/**
 * Called when a loot box reward is awarded.
 *
 * @param id            Player index
 * @param box_ent       Box entity index
 * @param reward        Reward value (amount of gold/exp/etc.)
 * @param was_jackpot   Whether this was a jackpot win
 *
 * @noreturn
 */
forward cod_box_reward(id, box_ent, reward, was_jackpot);

/**
 * Called when a loot box is stolen from another player.
 *
 * @param id        Original owner index
 * @param thief     Thief player index
 * @param box_ent   Box entity index
 *
 * @noreturn
 */
forward cod_box_stolen(id, thief, box_ent);

/**
 * Called when an admin action is logged.
 *
 * @param action    Action type (e.g., "BAN", "KICK", "GIVE_GOLD")
 * @param admin     Admin name who performed action
 * @param target    Target player name or "SERVER"
 * @param details   Action details
 *
 * @noreturn
 */
forward cod_admin_action_logged(const action[], const admin[], const target[], const details[]);

/**
 * Called when leaderboard reward is given.
 *
 * @param rank          Rank position (1-15)
 * @param player_name   Player name
 * @param credit        Credit reward amount
 * @param gold          Gold reward amount
 *
 * @noreturn
 */
forward cod_leaderboard_reward_given(rank, player_name[], credit, gold);

/**
 * Called when a kill effect is triggered.
 *
 * @param killer    Killer index
 * @param victim    Victim index
 * @param effect_id Effect ID triggered
 *
 * @noreturn
 */
forward cod_kill_effect_triggered(killer, victim, effect_id);

//=============================================================================
// FORWARD FUNCTIONS - Gap Protection Events
//=============================================================================

/**
 * Called when a player gains an underdog stack.
 *
 * @param id            Player index
 * @param new_stack     New stack count (1-5)
 * @param old_stack     Previous stack count
 *
 * @noreturn
 */
forward cod_underdog_stack_gained(id, new_stack, old_stack);

/**
 * Called when a player loses underdog stacks.
 *
 * @param id            Player index
 * @param new_stack     New stack count (0-4)
 * @param old_stack     Previous stack count
 *
 * @noreturn
 */
forward cod_underdog_stack_lost(id, new_stack, old_stack);

/**
 * Called when underdog stacks decay at round end.
 *
 * @param id            Player index
 * @param new_stack     New stack count after decay
 * @param old_stack     Previous stack count
 *
 * @noreturn
 */
forward cod_underdog_stack_decayed(id, new_stack, old_stack);

//=============================================================================
// FORWARD FUNCTIONS - Legacy Compatibility (From original cod.inc)
//=============================================================================

// Note: The following forwards are from the original COD Mod and are kept for
// compatibility with existing class/perk plugins. They are also used internally
// by COD:MW4 core.

/**
 * Called when player's access flags change.
 *
 * @param id        Player index
 * @param flags     New access flags
 *
 * @noreturn
 */
forward cod_flags_changed(id, flags);

/**
 * Called when player's class changes.
 *
 * @param id        Player index
 * @param class     New class index
 *
 * @noreturn
 */
forward cod_class_changed(id, class);

/**
 * Called when player's item changes.
 *
 * @param id        Player index
 * @param item      New item index
 *
 * @noreturn
 */
forward cod_item_changed(id, item);

/**
 * Called when player's render amount changes.
 *
 * @param id        Player index
 * @param render    New render amount (0-255)
 *
 * @noreturn
 */
forward cod_render_changed(id, render);

/**
 * Called when player's gravity changes.
 *
 * @param id        Player index
 * @param gravity   New gravity value (0.0-1.0)
 *
 * @noreturn
 */
forward cod_gravity_changed(id, Float:gravity);

/**
 * Called when player's speed changes.
 *
 * @param id        Player index
 * @param speed     New speed value (COD_FREEZE = frozen)
 *
 * @noreturn
 */
forward cod_speed_changed(id, Float:speed);

/**
 * Called before player receives damage (pre-armor).
 *
 * @param attacker      Attacker index
 * @param victim        Victim index
 * @param weapon        Weapon ID (CSW_*)
 * @param damage        Damage amount (can be modified)
 * @param damageBits    Damage flags (DMG_*)
 * @param hitPlace      Hit location (HIT_*)
 *
 * @return              COD_BLOCK to nullify damage, COD_CONTINUE otherwise
 */
forward cod_damage_pre(attacker, victim, weapon, &Float:damage, damageBits, hitPlace);

/**
 * Called after player receives damage (post-armor).
 *
 * @param attacker      Attacker index
 * @param victim        Victim index
 * @param weapon        Weapon ID (CSW_*)
 * @param damage        Damage amount dealt
 * @param damageBits    Damage flags (DMG_*)
 * @param hitPlace      Hit location (HIT_*)
 *
 * @noreturn
 */
forward cod_damage_post(attacker, victim, weapon, Float:damage, damageBits, hitPlace);

/**
 * Called before cod_inflict_damage executes.
 *
 * @param attacker      Attacker index
 * @param victim        Victim index
 * @param damage        Damage amount (can be modified)
 * @param factor        Intelligence bonus factor
 * @param flags         Damage flags (includes custom DMG_* flags)
 *
 * @return              COD_BLOCK to block damage, COD_CONTINUE otherwise
 */
forward cod_damage_inflict(attacker, victim, &Float:damage, Float:factor, flags);

/**
 * Called when a weapon is deployed.
 *
 * @param id        Player index
 * @param weapon    Weapon ID (CSW_*)
 * @param ent       Weapon entity index
 *
 * @noreturn
 */
forward cod_weapon_deploy(id, weapon, ent);

/**
 * Called when current weapon updates.
 *
 * @param id        Player index
 * @param weapon    New current weapon ID (CSW_*)
 *
 * @noreturn
 */
forward cod_cur_weapon(id, weapon);

/**
 * Called when player is assigned to a team.
 *
 * @param id        Player index
 * @param team      Team index (0=unassigned, 1=T, 2=CT, 3=spec)
 *
 * @noreturn
 */
forward cod_team_assign(id, team);

/**
 * Called when a player is killed.
 *
 * @param killer    Killer index
 * @param victim    Victim index
 * @param weapon    Weapon ID used for kill
 * @param hitPlace  Hit location (HIT_*)
 *
 * @noreturn
 */
forward cod_killed(killer, victim, weapon, hitPlace);

/**
 * Called when a player spawns.
 *
 * @param id        Player index
 * @param respawn   True if not first spawn of the round
 *
 * @noreturn
 */
forward cod_spawned(id, respawn);

/**
 * Called each frame for client commands.
 *
 * @param id            Player index
 * @param button        Current buttons (IN_*)
 * @param oldButton     Previous buttons
 * @param flags         Player flags (FL_*)
 * @param playerState   Render state (RENDER_*)
 *
 * @noreturn
 */
forward cod_cmd_start(id, button, oldButton, flags, playerState);

/**
 * Called when bomb planting starts.
 *
 * @param id    Planter index
 *
 * @noreturn
 */
forward cod_bomb_planting(id);

/**
 * Called when bomb is planted.
 *
 * @param id    Planter index
 *
 * @noreturn
 */
forward cod_bomb_planted(id);

/**
 * Called when bomb defusing starts.
 *
 * @param id    Defuser index
 *
 * @noreturn
 */
forward cod_bomb_defusing(id);

/**
 * Called when bomb is defused.
 *
 * @param id    Defuser index
 *
 * @noreturn
 */
forward cod_bomb_defused(id);

/**
 * Called when bomb explodes.
 *
 * @param planter   Planter index
 * @param defuser   Defuser index (0 if no defuser was present)
 *
 * @noreturn
 */
forward cod_bomb_explode(planter, defuser);

/**
 * Called when bomb is dropped.
 *
 * @param id    Player index who dropped the bomb
 *
 * @noreturn
 */
forward cod_bomb_dropped(id);

/**
 * Called when bomb is picked up.
 *
 * @param id    Player index who picked up the bomb
 *
 * @noreturn
 */
forward cod_bomb_picked(id);

/**
 * Called when a hostage is killed.
 *
 * @param id    Killer index
 *
 * @noreturn
 */
forward cod_hostage_killed(id);

/**
 * Called when a hostage is rescued.
 *
 * @param id    Rescuer index
 *
 * @noreturn
 */
forward cod_hostage_rescued(id);

/**
 * Called when all hostages are rescued.
 *
 * @param id    Last rescuer index
 *
 * @noreturn
 */
forward cod_hostages_rescued(id);

/**
 * Called on new round (after freeze time).
 *
 * @noreturn
 */
forward cod_new_round();

/**
 * Called on round start (when freeze time ends).
 *
 * @noreturn
 */
forward cod_start_round();

/**
 * Called on round restart.
 *
 * @noreturn
 */
forward cod_restart_round();

/**
 * Called on round end.
 *
 * @noreturn
 */
forward cod_end_round();

/**
 * Called when a round is won.
 *
 * @param team  Winning team (1=Terrorist, 2=CT)
 *
 * @noreturn
 */
forward cod_win_round(team);

/**
 * Called on map end (intermission).
 *
 * @noreturn
 */
forward cod_end_map();

/**
 * Called when data should be reset.
 *
 * @noreturn
 */
forward cod_reset_data();

/**
 * Called when stats data should be reset.
 *
 * @noreturn
 */
forward cod_reset_stats_data();

/**
 * Called when all data should be reset.
 *
 * @noreturn
 */
forward cod_reset_all_data();

/**
 * Called when medkit heals a player.
 *
 * @param id        Medkit owner index
 * @param player    Healed player index
 * @param healed    HP amount healed
 *
 * @return          Return >0 to reduce cooldown, <0 to increase, COD_BLOCK to block heal
 */
forward cod_medkit_heal(id, player, Float:healed);

/**
 * Called when poison damages a player.
 *
 * @param id        Poison owner index
 * @param player    Damaged player index
 * @param damage    Damage amount
 *
 * @return          Return >0 to reduce cooldown, <0 to increase, COD_BLOCK to block damage
 */
forward cod_poison_infect(id, player, Float:damage);

/**
 * Called when rocket explodes and damages players.
 *
 * @param id        Rocket owner index
 * @param player    Damaged player index
 * @param damage    Damage amount
 *
 * @return          Return >0 to reduce cooldown, <0 to increase, COD_BLOCK to block damage
 */
forward cod_rocket_explode(id, player, Float:damage);

/**
 * Called when mine explodes and damages players.
 *
 * @param id        Mine owner index
 * @param player    Damaged player index
 * @param damage    Damage amount
 *
 * @return          Return >0 to reduce cooldown, <0 to increase, COD_BLOCK to block damage
 */
forward cod_mine_explode(id, player, Float:damage);

/**
 * Called when dynamite explodes and damages players.
 *
 * @param id        Dynamite owner index
 * @param player    Damaged player index
 * @param damage    Damage amount
 *
 * @return          Return >0 to reduce cooldown, <0 to increase, COD_BLOCK to block damage
 */
forward cod_dynamite_explode(id, player, Float:damage);

/**
 * Called when thunder hits a player.
 *
 * @param id        Thunder owner index
 * @param player    Damaged player index
 * @param damage    Damage amount
 *
 * @return          Return >0 to reduce cooldown, <0 to increase, COD_BLOCK to block damage
 */
forward cod_thunder_reach(id, player, Float:damage);

/**
 * Called when teleport is used.
 *
 * @param id        Player index
 *
 * @return          Return >0 to reduce cooldown, <0 to increase
 */
forward cod_teleport_used(id);

//=============================================================================
// FORWARD FUNCTIONS - Item/Class Specific (Legacy compatibility)
//=============================================================================

/**
 * Called to check if player can use an item.
 *
 * @param id        Player index
 * @param value     Item value
 *
 * @return          COD_STOP to refuse access, COD_CONTINUE to allow
 */
forward cod_item_check(id);

/**
 * Called when item is given to a player.
 *
 * @param id        Player index
 * @param value     Item value
 *
 * @noreturn
 */
forward cod_item_enabled(id, value);

/**
 * Called when item is removed from a player.
 *
 * @param id        Player index
 *
 * @noreturn
 */
forward cod_item_disabled(id);

/**
 * Called when player with item spawns.
 *
 * @param id        Player index
 * @param respawn   True if not first spawn of round
 *
 * @noreturn
 */
forward cod_item_spawned(id, respawn);

/**
 * Called when player with item makes a kill.
 *
 * @param killer    Killer index
 * @param victim    Victim index
 * @param hitPlace  Hit location (HIT_*)
 *
 * @noreturn
 */
forward cod_item_kill(killer, victim, hitPlace);

/**
 * Called when player with item is killed.
 *
 * @param killer    Killer index
 * @param victim    Victim index
 * @param hitPlace  Hit location (HIT_*)
 *
 * @noreturn
 */
forward cod_item_killed(killer, victim, hitPlace);

/**
 * Called when item skill is used.
 *
 * @param id        Player index
 *
 * @noreturn
 */
forward cod_item_skill_used(id);

/**
 * Called when item is upgraded.
 *
 * @param id        Player index
 *
 * @noreturn
 */
forward cod_item_upgrade(id);

/**
 * Called to get item's current value.
 *
 * @param id        Player index
 *
 * @return          Item value (if applicable)
 */
forward cod_item_value(id);

/**
 * Called when item owner deals damage.
 *
 * @param attacker      Attacker index
 * @param victim        Victim index
 * @param weapon        Weapon ID
 * @param damage        Damage amount (can be modified, COD_BLOCK to block)
 * @param damageBits    Damage flags
 * @param hitPlace      Hit location
 *
 * @noreturn
 */
forward cod_item_damage_attacker(attacker, victim, weapon, &Float:damage, damageBits, hitPlace);

/**
 * Called when item owner takes damage.
 *
 * @param attacker      Attacker index
 * @param victim        Victim index
 * @param weapon        Weapon ID
 * @param damage        Damage amount (can be modified, COD_BLOCK to block)
 * @param damageBits    Damage flags
 * @param hitPlace      Hit location
 *
 * @noreturn
 */
forward cod_item_damage_victim(attacker, victim, weapon, &Float:damage, damageBits, hitPlace);

/**
 * Called when class is enabled.
 *
 * @param id            Player index
 * @param promotion     Class promotion step
 *
 * @return              COD_STOP to block class change, COD_CONTINUE to allow
 */
forward cod_class_enabled(id, promotion);

/**
 * Called when class is disabled.
 *
 * @param id            Player index
 * @param promotion     Class promotion step
 *
 * @noreturn
 */
forward cod_class_disabled(id, promotion);

/**
 * Called when player with class spawns.
 *
 * @param id            Player index
 * @param respawn       True if not first spawn of round
 *
 * @noreturn
 */
forward cod_class_spawned(id, respawn);

/**
 * Called when player with class makes a kill.
 *
 * @param killer        Killer index
 * @param victim        Victim index
 * @param hitPlace      Hit location (HIT_*)
 *
 * @noreturn
 */
forward cod_class_kill(killer, victim, hitPlace);

/**
 * Called when player with class is killed.
 *
 * @param killer        Killer index
 * @param victim        Victim index
 * @param hitPlace      Hit location (HIT_*)
 *
 * @noreturn
 */
forward cod_class_killed(killer, victim, hitPlace);

/**
 * Called when class skill is used.
 *
 * @param id            Player index
 *
 * @noreturn
 */
forward cod_class_skill_used(id);

/**
 * Called when class owner deals damage.
 *
 * @param attacker      Attacker index
 * @param victim        Victim index
 * @param weapon        Weapon ID
 * @param damage        Damage amount (can be modified, COD_BLOCK to block)
 * @param damageBits    Damage flags
 * @param hitPlace      Hit location
 *
 * @noreturn
 */
forward cod_class_damage_attacker(attacker, victim, weapon, &Float:damage, damageBits, hitPlace);

/**
 * Called when class owner takes damage.
 *
 * @param attacker      Attacker index
 * @param victim        Victim index
 * @param weapon        Weapon ID
 * @param damage        Damage amount (can be modified, COD_BLOCK to block)
 * @param damageBits    Damage flags
 * @param hitPlace      Hit location
 *
 * @noreturn
 */
forward cod_class_damage_victim(attacker, victim, weapon, &Float:damage, damageBits, hitPlace);

//=============================================================================
// STOCK FUNCTIONS (Helper Macros & Utilities)
//=============================================================================

/**
 * Validates if a player index is within valid range.
 *
 * @param id    Player index to validate
 *
 * @return      1 if index is between 1 and MAX_PLAYERS, 0 otherwise
 */
#define is_user_valid(%1) (1 <= %1 <= MAX_PLAYERS)

/**
 * Returns the smaller of two values.
 *
 * @param a     First value
 * @param b     Second value
 *
 * @return      The smaller value
 */
stock min(a, b) {
    return (a < b) ? a : b;
}

/**
 * Returns the larger of two values.
 *
 * @param a     First value
 * @param b     Second value
 *
 * @return      The larger value
 */
stock max(a, b) {
    return (a > b) ? a : b;
}

/**
 * Clamps a value between lower and upper bounds.
 *
 * @param value     Value to clamp
 * @param lower     Lower bound
 * @param upper     Upper bound
 *
 * @return          Clamped value
 */
stock clamp(value, lower, upper) {
    return max(lower, min(upper, value));
}

/**
 * Returns the absolute value of a number.
 *
 * @param x     Number to get absolute value of
 *
 * @return      Absolute value
 */
stock abs(x) {
    return x > 0 ? x : -x;
}

/**
 * Converts milliseconds to seconds (Float).
 *
 * @param ms    Milliseconds
 *
 * @return      Seconds as Float
 */
stock Float:ms_to_sec(ms) {
    return float(ms) / 1000.0;
}

/**
 * Converts seconds to milliseconds (integer).
 *
 * @param sec   Seconds (Float)
 *
 * @return      Milliseconds as integer
 */
stock sec_to_ms(Float:sec) {
    return floatround(sec * 1000.0);
}

/**
 * Formats HP display with K/H/U notation for large numbers.
 * Example: 1500 -> "1.5K", 10000 -> "10K", 12345 -> "12.3K"
 *
 * @param hp        Health points to format
 * @param output    Buffer to store formatted string
 * @param len       Maximum buffer length
 *
 * @return          Number of cells written
 */
stock format_hp_display(hp, output[], len) {
    if (hp >= 10000000) {
        return formatex(output, len, "%.1fH", float(hp) / 1000000.0);
    } else if (hp >= 1000000) {
        return formatex(output, len, "%.1fM", float(hp) / 1000000.0);
    } else if (hp >= 10000) {
        return formatex(output, len, "%.1fK", float(hp) / 1000.0);
    } else if (hp >= 1000) {
        return formatex(output, len, "%d", hp);
    }
    return formatex(output, len, "%d", hp);
}

/**
 * Calculates percentage and returns formatted string.
 *
 * @param current   Current value
 * @param max       Maximum value
 * @param output    Buffer to store formatted string
 * @param len       Maximum buffer length
 *
 * @return          Number of cells written
 */
stock format_percentage(current, max, output[], len) {
    if (max <= 0) {
        return formatex(output, len, "0%%");
    }
    new percent = (current * 100) / max;
    return formatex(output, len, "%d%%", percent);
}

/**
 * Creates a visual progress bar using characters.
 *
 * @param percent   Percentage (0-100)
 * @param bar_len   Desired bar length in characters
 * @param output    Buffer to store bar string
 * @param len       Maximum buffer length
 *
 * @return          Number of cells written
 */
stock format_progress_bar(percent, bar_len, output[], len) {
    if (bar_len > len - 1) bar_len = len - 1;
    
    new filled = (percent * bar_len) / 100;
    new empty = bar_len - filled;
    new pos = 0;
    
    pos += formatex(output[pos], len - pos, "[");
    for (new i = 0; i < filled; i++) pos += formatex(output[pos], len - pos, "=");
    if (filled < bar_len) pos += formatex(output[pos], len - pos, ">");
    for (new i = 0; i < empty - 1; i++) pos += formatex(output[pos], len - pos, " ");
    pos += formatex(output[pos], len - pos, "]");
    
    return pos;
}

//=============================================================================
// END OF FILE: cod.inc
//=============================================================================
