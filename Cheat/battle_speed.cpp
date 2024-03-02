#include "battle_speed.h"

#include "engine.h"
#include "globals.h"
#include "hooks.h"

#include "utils.h"

#include "imgui_internal.h"

namespace BattleSpeed
{

	static void set_speedHandler(void* _this, float value)
	{
		FLOAT flValue = value;

		if (Options.bBattleSpeed)
		{
			__try
			{
				switch (Engine::GetPhaseType())
				{
				case RPG::Client::GamePhaseType_BattleLineup:
				case RPG::Client::GamePhaseType_QABattleLineup:
				case RPG::Client::GamePhaseType_Battle:
				case RPG::Client::GamePhaseType_BattleNew:
					flValue = Options.flBattleSpeed;
					break;
				default:
					break;
				}
			}
			__except (EXCEPTION_EXECUTE_HANDLER)
			{
				printf("BattleSpeed::set_speedHandler(), exception 0x%X\n", GetExceptionCode());

				flValue = value;
			}
		}

		return CALL_ORIGIN(set_speedHandler, _this, flValue);
	}

	bool get_lengthHandler()
	{
		if (!Options.bBattleSpeedDisableDelay)
			return false;

		switch (Engine::GetPhaseType())
		{
		case RPG::Client::GamePhaseType_BattleLineup:
		case RPG::Client::GamePhaseType_QABattleLineup:
		case RPG::Client::GamePhaseType_Battle:
		case RPG::Client::GamePhaseType_BattleNew:
			return true;
		default:
			return false;
		}
	}

	float clip_get_lengthHandler(void* _this)
	{
		__try
		{
			if (get_lengthHandler())
				return 0.f;
		}
		__except (EXCEPTION_EXECUTE_HANDLER)
		{
			printf("BattleSpeed::clip_get_lengthHandler(), exception 0x%X\n", GetExceptionCode());
		}

		return CALL_ORIGIN(clip_get_lengthHandler, _this);
	}

	float state_get_lengthHandler(void* _this)
	{
		__try
		{
			if (get_lengthHandler())
				return 0.f;
		}
		__except (EXCEPTION_EXECUTE_HANDLER)
		{
			printf("BattleSpeed::state_get_lengthHandler(), exception 0x%X\n", GetExceptionCode());
		}
		return CALL_ORIGIN(state_get_lengthHandler, _this);
	}

	int curve_get_lengthHandler(void* _this)
	{
		__try
		{
			if (get_lengthHandler())
				return 0;
		}
		__except (EXCEPTION_EXECUTE_HANDLER)
		{
			printf("BattleSpeed::curve_get_lengthHandler(), exception 0x%X\n", GetExceptionCode());
		}
		return CALL_ORIGIN(curve_get_lengthHandler, _this);
	}

	float beziercurve_get_lengthHandler(void* _this)
	{
		__try
		{
			if (get_lengthHandler())
				return 0.f;
		}
		__except (EXCEPTION_EXECUTE_HANDLER)
		{
			printf("BattleSpeed::beziercurve_get_lengthHandler(), exception 0x%X\n", GetExceptionCode());
		}
		return CALL_ORIGIN(beziercurve_get_lengthHandler, _this);
	}

	namespace Bypass
	{
		PVOID lpCELDMFBOAPJ = NULL, lpDDDMHOACNPH = NULL;

		bool TimeCheck(int iTotalBattleTime, int iDeltaTime, int iTotalSkillPerformTime)
		{
			FLOAT fTimeScale = (FLOAT)iTotalBattleTime / iDeltaTime;

			if (fTimeScale < 0.85f || fTimeScale > 2.5f)
				return TRUE;

			if (iTotalBattleTime < iTotalSkillPerformTime)
				return TRUE;

			//if(iServerStartBattle - iServerEndBattle < iDeltaTime) // impossible to bypass 
			//	return TRUE;

			return FALSE;
		}

		void TimeBypass(float* lpTotalBattleTime, float* lpDeltaTime, float fTotalSkillPerformTime)
		{
			if (*lpTotalBattleTime < fTotalSkillPerformTime)
				*lpTotalBattleTime = fTotalSkillPerformTime + RandomFloat(0.f, 1.f);

			*lpDeltaTime = *lpTotalBattleTime / RandomFloat(2.f, 2.5f);

			if (*lpDeltaTime < 1.f)
				*lpDeltaTime = *lpTotalBattleTime;
		}

		void* BuildPVEStatisticsHandler(RPG::GameCore::StatisticsComponent* _this)
		{
			if (_this)
			{
				FLOAT fRealBattleTime = RPG::Client::EIELKABBJGE::HKBGDIAHJEP(lpCELDMFBOAPJ, TRUE);
				FLOAT fBattleStartTime = RPG::Client::EIELKABBJGE::HKBGDIAHJEP(lpDDDMHOACNPH, TRUE);

				FLOAT fCurrentTime = UnityEngine::Time::get_time();

				FLOAT fDelta = fCurrentTime - fBattleStartTime;
				FLOAT fTimeScale = fRealBattleTime / fDelta;

				printf("fRealBattleTime: %f\n", fRealBattleTime);
				printf("fBattleStartTime: %f\n", fBattleStartTime);
				printf("fCurrentTime: %f\n", fCurrentTime);
				printf("fDelta: %f\n", fDelta);
				printf("fTimeScale: %f\n", fTimeScale);
				printf("fTotalSkillPerformTime: %f\n", _this->_totalSkillPerformTime);

				if (TimeCheck((INT)fRealBattleTime, (INT)fDelta, (INT)_this->_totalSkillPerformTime))
				{
					FLOAT fOldDelta = fDelta;

					TimeBypass(&fRealBattleTime, &fDelta, _this->_totalSkillPerformTime);

					printf("Bypass->fRealBattleTime: %f\n", fRealBattleTime);
					printf("Bypass->fDelta: %f\n", fDelta);

					RPG::Client::EIELKABBJGE::JEBJMEIBFMP(lpCELDMFBOAPJ, fRealBattleTime);
					RPG::Client::EIELKABBJGE::JEBJMEIBFMP(lpDDDMHOACNPH, fCurrentTime - fDelta);

					if (fOldDelta < fDelta)
					{
						FLOAT fDelay = 1000.f * (fDelta - fOldDelta);

						Beep(600, 200);

						Sleep((INT)fDelay);
					}
				}
			}

			return CALL_ORIGIN(BuildPVEStatisticsHandler, _this);
		}

		void MMOFLGJNNOFHandler(RPG::Client::MDCGJBLKAPI* _this, bool BBOMECGIIPP, bool NDLAHGEPBJJ)
		{
			if (_this)
			{
				__try
				{
					RPG::GameCore::TurnBasedGameMode* lpTurnBasedGameMode = Engine::GetTurnBasedGameMode(_this);

					if (lpTurnBasedGameMode)
					{
						RPG::Client::CJPMFGOOLKO* lpBattleCounter = lpTurnBasedGameMode->BattleCounter;

						if (lpBattleCounter)
						{
							lpCELDMFBOAPJ = lpBattleCounter->CELDMFBOAPJ;
							lpDDDMHOACNPH = lpBattleCounter->DDDMHOACNPH;
						}
					}
				}
				__except (EXCEPTION_EXECUTE_HANDLER)
				{
					printf("BattleSpeed::MMOFLGJNNOFHandler(), exception 0x%X\n", GetExceptionCode());
				}
			}

			return CALL_ORIGIN(MMOFLGJNNOFHandler, _this, BBOMECGIIPP, NDLAHGEPBJJ);
		}
	}

	void Render()
	{
		ImGui::BeginGroupPanel("Battle Speed");

		ImGui::Checkbox("Enable", &Options.bBattleSpeed);

		if (Options.bBattleSpeed)
		{
			ImGui::Indent();

			ImGui::Checkbox("Disable Delay", &Options.bBattleSpeedDisableDelay);

			ImGui::SliderFloat("Value", &Options.flBattleSpeed, 0.0f, 1000.f, "%.1f");

			ImGui::Unindent();
		}

		ImGui::EndGroupPanel();
	}

	void Update()
	{
	}

	void Start()
	{
		CreateHook(UnityEngine::Animator::set_speed, set_speedHandler);
		CreateHook(UnityEngine::AnimationClip::get_length, clip_get_lengthHandler);
		CreateHook(UnityEngine::AnimationState::get_length, state_get_lengthHandler);
		CreateHook(UnityEngine::AnimationCurve::get_length, curve_get_lengthHandler);
		CreateHook(RPG::Client::BezierCurve::get_Length, beziercurve_get_lengthHandler);
		CreateHook(RPG::Client::MDCGJBLKAPI::MMOFLGJNNOF, Bypass::MMOFLGJNNOFHandler);
		CreateHook(RPG::GameCore::StatisticsComponent::BuildPVEStatistics, Bypass::BuildPVEStatisticsHandler);
	}
}