//
// csgo sdk
//

#pragma once

#include "matrix.hpp"
#include "vector.hpp"

#include "../core/interfaces.hpp"
#include "../core/netvars.hpp"

class CBaseCombatWeapon;

enum item_definition_index_t : unsigned short
{
  WEAPON_NONE = 0,
  WEAPON_FIRST = 1,
  WEAPON_DEAGLE = WEAPON_FIRST,
  WEAPON_ELITE,
  WEAPON_FIVE_SEVEN,
  WEAPON_GLOCK,
  WEAPON_AK47 = 7,
  WEAPON_AUG,
  WEAPON_AWP,
  WEAPON_FAMAS,
  WEAPON_G3SG1,
  WEAPON_GALILAR = 13,
  WEAPON_M249,
  WEAPON_M4A4 = 16,
  WEAPON_MAC10,
  WEAPON_P90 = 19,
  WEAPON_MP5 = 23,
  WEAPON_UMP45,
  WEAPON_XM1014,
  WEAPON_BIZON,
  WEAPON_MAG7,
  WEAPON_NEGEV,
  WEAPON_SAWEDOFF,
  WEAPON_TEC9,
  WEAPON_TASER,
  WEAPON_HKP2000,
  WEAPON_MP7,
  WEAPON_MP9,
  WEAPON_NOVA,
  WEAPON_P250,
  WEAPON_SHIELD,
  WEAPON_SCAR20,
  WEAPON_SG556,
  WEAPON_SSG08,
  WEAPON_KNIFE_GG,
  WEAPON_KNIFE_CT,
  WEAPON_FLASHBANG,
  WEAPON_HE_GRENADE,
  WEAPON_SMOKE_GRENADE,
  WEAPON_MOLOTOV,
  WEAPON_DECOY,
  WEAPON_INCENDIRARY_GRENADE,
  WEAPON_C4,
  ITEM_KEVLAR,
  ITEM_ASSAULTSUIT,
  ITEM_HEAVYASSAULTSUIT,
  ITEM_NVG = 54,
  ITEM_DEFUSER,
  ITEM_CUTTERS,
  WEAPON_HEALTHSHOT,
  WEAPON_KNIFE_T = 59,
  WEAPON_M4A1_SILENCER,
  WEAPON_USP_SILENCER,
  WEAPON_CZ75A = 63,
  WEAPON_REVOLVER,
  WEAPON_TAGRENADE = 68,
  WEAPON_FISTS,
  WEAPON_BREACH_CHARGE,
  WEAPON_TABLET = 72,
  WEAPON_MELEE = 74,
  WEAPON_AXE,
  WEAPON_HAMMER,
  WEAPON_SPANNER = 78,
  WEAPON_KNIFE_SPECTRAL = 80,
  WEAPON_FIREBOMB,
  WEAPON_DIVERSION,
  WEAPON_FRAG_GRENADE,
  WEAPON_SNOWBALL,
  WEAPON_BUMPMINE,
  WEAPON_KNIFE_BAYONET = 500,
  WEAPON_KNIFE_CSS = 503,
  WEAPON_KNIFE_FLIP = 505,
  WEAPON_KNIFE_GUT,
  WEAPON_KNIFE_KARAMBIT,
  WEAPON_KNIFE_M9_BAYONET,
  WEAPON_KNIFE_TACTICAL,
  WEAPON_KNIFE_FALCHION = 512,
  WEAPON_KNIFE_BOWIE = 514,
  WEAPON_KNIFE_BUTTERFLY,
  WEAPON_KNIFE_DAGGER,
  WEAPON_KNIFE_CORD,
  WEAPON_KNIFE_CANIS,
  WEAPON_KNIFE_URSUS,
  WEAPON_KNIFE_NAVAJA,
  WEAPON_KNIFE_OUTDOOR,
  WEAPON_KNIFE_STILETTO,
  WEAPON_KNIFE_TALON,
  WEAPON_KNIFE_SKELETON = 525,
  STUDDED_BLOODHOUND_GLOVES = 5027,
  GLOVES_DEFAULT_T,
  GLOVES_DEFAULT_CT,
  GLOVES_SPORTY,
  GLOVES_SLICK,
  GLOVES_HANDWRAPS,
  GLOVES_MOTORCYCLE,
  GLOVEL_SPECIALIST,
  GLOVES_STUDDED_HYDRA,
  CUSTOMPLAYER_T_MAP_BASED,
  CUSTOMPLAYER_CT_MAP_BASED,
  CUSTOMPLAYER_TM_ANARCHIST,
  CUSTOMPLAYER_TM_ANARCHIST_VARIANTA,
  CUSTOMPLAYER_TM_ANARCHIST_VARIANTB,
  CUSTOMPLAYER_TM_ANARCHIST_VARIANTC,
  CUSTOMPLAYER_TM_ANARCHIST_VARIANTD,
  CUSTOMPLAYER_TM_PIRATE,
  CUSTOMPLAYER_TM_PIRATE_VARIANTA,
  CUSTOMPLAYER_TM_PIRATE_VARIANTB,
  CUSTOMPLAYER_TM_PIRATE_VARIANTC,
  CUSTOMPLAYER_TM_PIRATE_VARIANTD,
  CUSTOMPLAYER_TM_PROFESSIONAL,
  CUSTOMPLAYER_TM_PROFESSIONAL_VAR1,
  CUSTOMPLAYER_TM_PROFESSIONAL_VAR2,
  CUSTOMPLAYER_TM_PROFESSIONAL_VAR3,
  CUSTOMPLAYER_TM_PROFESSIONAL_VAR4,
  CUSTOMPLAYER_TM_SEPARATIST,
  CUSTOMPLAYER_TM_SEPARATIST_VARIANTA,
  CUSTOMPLAYER_TM_SEPARATIST_VARIANTB,
  CUSTOMPLAYER_TM_SEPARATIST_VARIANTC,
  CUSTOMPLAYER_TM_SEPARATIST_VARIANTD,
  CUSTOMPLAYER_CTM_GIGN,
  CUSTOMPLAYER_CTM_GIGN_VARIANTA,
  CUSTOMPLAYER_CTM_GIGN_VARIANTB,
  CUSTOMPLAYER_CTM_GIGN_VARIANTC,
  CUSTOMPLAYER_CTM_GIGN_VARIANTD,
  CUSTOMPLAYER_CTM_GSG9,
  CUSTOMPLAYER_CTM_GSG9_VARIANTA,
  CUSTOMPLAYER_CTM_GSG9_VARIANTB,
  CUSTOMPLAYER_CTM_GSG9_VARIANTC,
  CUSTOMPLAYER_CTM_GSG9_VARIANTD,
  CUSTOMPLAYER_CTM_IDF,
  CUSTOMPLAYER_CTM_IDF_VARIANTB,
  CUSTOMPLAYER_CTM_IDF_VARIANTC,
  CUSTOMPLAYER_CTM_IDF_VARIANTD,
  CUSTOMPLAYER_CTM_IDF_VARIANTE,
  CUSTOMPLAYER_CTM_IDF_VARIANTF,
  CUSTOMPLAYER_CTM_SWAT,
  CUSTOMPLAYER_CTM_SWAT_VARIANTA,
  CUSTOMPLAYER_CTM_SWAT_VARIANTB,
  CUSTOMPLAYER_CTM_SWAT_VARIANTC,
  CUSTOMPLAYER_CTM_SWAT_VARIANTD,
  CUSTOMPLAYER_CTM_SAS_VARIANTA,
  CUSTOMPLAYER_CTM_SAS_VARIANTB,
  CUSTOMPLAYER_CTM_SAS_VARIANTC,
  CUSTOMPLAYER_CTM_SAS_VARIANTD,
  CUSTOMPLAYER_CTM_ST6,
  CUSTOMPLAYER_CTM_ST6_VARIANTA,
  CUSTOMPLAYER_CTM_ST6_VARIANTB,
  CUSTOMPLAYER_CTM_ST6_VARIANTC,
  CUSTOMPLAYER_CTM_ST6_VARIANTD,
  CUSTOMPLAYER_TM_BALKAN_VARIANTE,
  CUSTOMPLAYER_TM_BALKAN_VARIANTA,
  CUSTOMPLAYER_TM_BALKAN_VARIANTB,
  CUSTOMPLAYER_TM_BALKAN_VARIANTC,
  CUSTOMPLAYER_TM_BALKAN_VARIANTD,
  CUSTOMPLAYER_TM_JUMPSUIT_VARIANTA,
  CUSTOMPLAYER_TM_JUMPSUIT_VARIANTB,
  CUSTOMPLAYER_TM_JUMPSUIT_VARIANTC,
  CUSTOMPLAYER_TM_PHOENIX_HEAVY,
  CUSTOMPLAYER_CTM_HEAVY,
  CUSTOMPLAYER_TM_LEET_VARIANTA = 5100,
  CUSTOMPLAYER_TM_LEET_VARIANTB,
  CUSTOMPLAYER_TM_LEET_VARIANTC,
  CUSTOMPLAYER_TM_LEET_VARIANTD,
  CUSTOMPLAYER_TM_LEET_VARIANTE,
  CUSTOMPLAYER_TM_LEET_VARIANTG,
  CUSTOMPLAYER_TM_LEET_VARIANTH,
  CUSTOMPLAYER_TM_LEET_VARIANTI,
  CUSTOMPLAYER_TM_LEET_VARIANTF,
  CUSTOMPLAYER_TM_PHOENIX = 5200,
  CUSTOMPLAYER_TM_PHOENIX_VARIANTA,
  CUSTOMPLAYER_TM_PHOENIX_VARIANTB,
  CUSTOMPLAYER_TM_PHOENIX_VARIANTC,
  CUSTOMPLAYER_TM_PHOENIX_VARIANTD,
  CUSTOMPLAYER_TM_PHOENIX_VARIANTH,
  CUSTOMPLAYER_TM_PHOENIX_VARIANTF,
  CUSTOMPLAYER_TM_PHOENIX_VARIANTG,
  CUSTOMPLAYER_CTM_FBI = 5300,
  CUSTOMPLAYER_CTM_FBI_VARIANTA,
  CUSTOMPLAYER_CTM_FBI_VARIANTC,
  CUSTOMPLAYER_CTM_FBI_VARIANTD,
  CUSTOMPLAYER_CTM_FBI_VARIANTE,
  CUSTOMPLAYER_CTM_FBI_VARIANTF,
  CUSTOMPLAYER_CTM_FBI_VARIANTG,
  CUSTOMPLAYER_CTM_FBI_VARIANTH,
  CUSTOMPLAYER_CTM_FBI_VARIANTB,
  CUSTOMPLAYER_CTM_ST6_VARIANTK = 5400,
  CUSTOMPLAYER_CTM_ST6_VARIANTE,
  CUSTOMPLAYER_CTM_ST6_VARIANTG,
  CUSTOMPLAYER_CTM_ST6_VARIANTM,
  CUSTOMPLAYER_CTM_ST6_VARIANTI,
  CUSTOMPLAYER_TM_BALKAN_VARIANTF = 5500,
  CUSTOMPLAYER_TM_BALKAN_VARIANTI,
  CUSTOMPLAYER_TM_BALKAN_VARIANTG,
  CUSTOMPLAYER_TM_BALKAN_VARIANTJ,
  CUSTOMPLAYER_TM_BALKAN_VARIANTH,
  CUSTOMPLAYER_CTM_SAS = 5600,
  CUSTOMPLAYER_CTM_SAS_VARIANTF,
};

enum team_id_t : int
{
  NONE = 0,
  SPECTATOR = 1,
  TERRORIST = 2,
  COUNTER_TERRORIST = 3
};

enum entity_flags_t : int
{
  ON_GROUND = (1 << 0),
  DUCKING = (1 << 1),
  PARTIAL_GROUND = (1 << 17),
  STEP_MOVEMENT = (1 << 21),
  UNBLOCKABLE_BY_PLAYER = (1 << 30)
};

enum class_id_t : int
{
  AK_47 = 1,
  PLAYER = 40,
  DECOY_GREANDE = 47,
  FLASHBANG_GRENADE = 77,
  EXPLOSIVE_GRENADE = 96,
  INCENDIARY_GRENADE = 99,
  KNIFE = 107,
  KNIFE_GOLDEN = 108,
  MOLOTOV_GRENADE = 112,
  PRECIPITATION = 137,
  SMOKE_GRENADE = 155,
  SMOKE_GRENADE_PROJECTILE = 156
};

enum observer_mode_t : int
{
  MODE_NONE = 0,
  MODE_DEATHCAM,
  MODE_FREEZECAM,
  MODE_FIXED,
  MODE_IN_EYE,
  MODE_CHASE,
  MODE_ROAMING,
};

enum PrecipitationType_t : int
{
  PRECIPITATION_TYPE_RAIN = 0,
  PRECIPITATION_TYPE_SNOW,
  PRECIPITATION_TYPE_ASH,
  PRECIPITATION_TYPE_SNOWFALL,
  PRECIPITATION_TYPE_PARTICLERAIN,
  PRECIPITATION_TYPE_PARTICLEASH,
  PRECIPITATION_TYPE_PARTICLERAINSTORM,
  PRECIPITATION_TYPE_PARTICLESNOW
};

struct PostProcessParameters_t
{
  float fadetime;
  float localcontraststrength;
  float localcontrastedgestrength;
  float vignettestart;
  float vignetteend;
  float vignetteblurstrength;
  float fadetoblackstrength;
  float depthblurfocaldistance;
  float depthblurstrength;
  float screenblurstrength;
  float filmgrainstrength;
};

class CPostProcessController
{
public:
  // netvars
  CNetworkVarPtr(PostProcessParameters_t, m_flPostProcessParameters, "DT_PostProcessController->m_flPostProcessParameters");
  CNetworkVarPtr(bool, m_bMaster, "DT_PostProcessController->m_bMaster");
};

class CSmokeGrenadeProjectile
{
public:
  // netvars
  CNetworkVarPtr(bool, m_bDidSmokeEffect, "DT_SmokeGrenadeProjectile->m_bDidSmokeEffect");
  CNetworkVarPtr(int, m_nSmokeEffectTickBegin, "DT_SmokeGrenadeProjectile->m_nSmokeEffectTickBegin");
};

class CTonemapController
{
public:
  // netvars
  CNetworkVarPtr(bool, m_bUseCustomAutoExposureMin, "DT_EnvTonemapController->m_bUseCustomAutoExposureMin");
  CNetworkVarPtr(bool, m_bUseCustomAutoExposureMax, "DT_EnvTonemapController->m_bUseCustomAutoExposureMax");
  CNetworkVarPtr(float, m_flCustomAutoExposureMin, "DT_EnvTonemapController->m_flCustomAutoExposureMin");
  CNetworkVarPtr(float, m_flCustomAutoExposureMax, "DT_EnvTonemapController->m_flCustomAutoExposureMax");
};

class CScriptCreatedItem
{
public:
  bool IsRifle()
  {
    switch (m_iItemDefinitionIndex())
    {
    case item_definition_index_t::WEAPON_AK47:
    case item_definition_index_t::WEAPON_GALILAR:
    case item_definition_index_t::WEAPON_SG556:
    case item_definition_index_t::WEAPON_M4A4:
    case item_definition_index_t::WEAPON_M4A1_SILENCER:
    case item_definition_index_t::WEAPON_AUG:
      return true;
    default:
      return false;
    }
  }

  bool IsPistol()
  {
    switch (m_iItemDefinitionIndex())
    {
    case item_definition_index_t::WEAPON_DEAGLE:
    case item_definition_index_t::WEAPON_GLOCK:
    case item_definition_index_t::WEAPON_HKP2000:
    case item_definition_index_t::WEAPON_P250:
    case item_definition_index_t::WEAPON_CZ75A:
    case item_definition_index_t::WEAPON_TEC9:
    case item_definition_index_t::WEAPON_FIVE_SEVEN:
    case item_definition_index_t::WEAPON_REVOLVER:
    case item_definition_index_t::WEAPON_USP_SILENCER:
    case item_definition_index_t::WEAPON_ELITE:
      return true;
    default:
      return false;
    }
  }

  bool IsSniper()
  {
    switch (m_iItemDefinitionIndex())
    {
    case item_definition_index_t::WEAPON_AWP:
    case item_definition_index_t::WEAPON_SSG08:
    case item_definition_index_t::WEAPON_SCAR20:
    case item_definition_index_t::WEAPON_G3SG1:
      return true;
    default:
      return false;
    }
  }

  bool IsGrenade()
  {
    switch (m_iItemDefinitionIndex())
    {
    case item_definition_index_t::WEAPON_FRAG_GRENADE:
    case item_definition_index_t::WEAPON_HE_GRENADE:
    case item_definition_index_t::WEAPON_INCENDIRARY_GRENADE:
    case item_definition_index_t::WEAPON_MOLOTOV:
    case item_definition_index_t::WEAPON_SMOKE_GRENADE:
    case item_definition_index_t::WEAPON_TAGRENADE:
    case item_definition_index_t::WEAPON_FLASHBANG:
    case item_definition_index_t::WEAPON_DECOY:
    case item_definition_index_t::WEAPON_SNOWBALL:
      return true;
    default:
      return false;
    }
  }

  // netvars
  CNetworkVar(unsigned short, m_iItemDefinitionIndex, "DT_ScriptCreatedItem->m_iItemDefinitionIndex");
};

class CAttributeContainer
{
public:
  // netvars
  CNetworkVarPtr(CScriptCreatedItem, m_Item, "DT_AttributeContainer->m_Item");
};

class CCollision
{
public:
  // netvars
  CNetworkVar(vec3_t, m_vecMins, "DT_CollisionProperty->m_vecMins");
  CNetworkVar(vec3_t, m_vecMaxs, "DT_CollisionProperty->m_vecMaxs");
};

class IClientEntity : public IClientNetworkable, public IClientRenderable
{
public:
  inline vec3_t GetAbsOrigin()
  {
    return memory::vfunc<12, const vec3_t &>(this);
  }

  inline void SetModelIndex(int index)
  {
    return memory::vfunc<111, void>(this, index);
  }

  inline vec3_t GetBonePosition(int bone)
  {

    matrix_t<float, 3, 4> matrix[128];

    if (SetupBones(matrix, 128, 0x100, 0))
    {
      return vec3_t(matrix[bone][0][3], matrix[bone][1][3], matrix[bone][2][3]);
    }

    return {0.f, 0.f, 0.f};
  }

  inline vec3_t GetEyePosition()
  {
    return (m_vecOrigin() + m_vecViewOffset());
  }

  // offsets
  COffsetPtr(IClientNetworkable, GetClientNetworkable, 0x10);

  // netvars
  CNetworkVar(int, m_iHealth, "DT_BasePlayer->m_iHealth");
  CNetworkVar(bool, m_bGunGameImmunity, "DT_CSPlayer->m_bGunGameImmunity");
  CNetworkVar(entity_flags_t, m_fFlags, "DT_BasePlayer->m_fFlags");
  CNetworkVar(bool, m_bInBombZone, "DT_CSPlayer->m_bInBombZone");
  CNetworkVar(int, m_iTeamNum, "DT_BaseEntity->m_iTeamNum");
  CNetworkVar(float, m_flSimulationTime, "DT_BaseEntity->m_flSimulationTime");
  CNetworkVar(vec3_t, m_vecOrigin, "DT_BaseEntity->m_vecOrigin");
  CNetworkVar(vec3_t, m_vecViewOffset, "DT_LocalPlayerExclusive->m_vecViewOffset[0]");
  CNetworkVar(vec3_t, m_vecMins, "DT_BaseEntity->m_vecMins");
  CNetworkVar(vec3_t, m_vecMaxs, "DT_BaseEntity->m_vecMaxs");
  CNetworkVar(float, m_flFlashDuration, "DT_CSPlayer->m_flFlashDuration");
  CNetworkVar(bool, m_bIsScoped, "DT_CSPlayer->m_bIsScoped");
  CNetworkVarPtr(bool, m_bCameraManXRay, "DT_BasePlayer->m_bCameraManXRay");
  CNetworkVarPtr(CTonemapController, m_hTonemapController, "DT_LocalPlayerExclusive->m_hTonemapController");
  CNetworkVarPtr(CPostProcessController, m_hPostProcessCtrl, "DT_BasePlayer->m_hPostProcessCtrl");
  CNetworkVarPtr(observer_mode_t, m_iObserverMode, "DT_BasePlayer->m_iObserverMode");
  CNetworkVarPtr(bool, m_bSpotted, "DT_BaseEntity->m_bSpotted");
  CNetworkVarPtr(bool, m_bSpottedByMask, "DT_BaseEntity->m_bSpottedByMask");
  CNetworkVarPtr(float, m_flFlashMaxAlpha, "DT_CSPlayer->m_flFlashMaxAlpha");
  CNetworkVarPtr(CBaseCombatWeapon, m_hActiveWeapon, "DT_BaseCombatCharacter->m_hActiveWeapon");
  CNetworkVarRef(CCollision, m_Collision, "DT_BaseEntity->m_Collision");
  CNetworkVarRef(int, m_nTickBase, "DT_LocalPlayerExclusive->m_nTickBase");
  CNetworkVar(vec3_t, m_vecVelocity, "DT_LocalPlayerExclusive->m_vecVelocity[0]");
  CNetworkVar(float, m_flStamina, "DT_CSLocalPlayerExclusive->m_flStamina");
};

class CBaseCombatWeapon : public IClientEntity
{
public:
  // netvars
  CNetworkVar(int, m_iClip1, "DT_BaseCombatWeapon->m_iClip1");
  CNetworkVarPtr(CAttributeContainer, m_AttributeManager, "DT_BaseAttributableItem->m_AttributeManager");
};

class CPrecipitation : public IClientEntity
{
public:
  CNetworkVarRef(PrecipitationType_t, m_nPrecipType, "DT_Precipitation->m_nPrecipType");
  CNetworkVarRefPadded(void *, m_MaterialHandle, "DT_Precipitation->m_nPrecipType", -36);
};