#include "auto_puzzle.h"

#include "engine.h"
#include "globals.h"
#include "hooks.h"

#include "utils.h"

#include "imgui_internal.h"

namespace AutoPuzzle
{
	bool bAutoPuzzle = FALSE;

	namespace CablePuzzle
	{
		static bool LADNBFDOAMJHandler(RPG::Client::Prop::CablePuzzleBoard* _this, void* FMJLOIDBOKI, void* BHMGPLJEDCH)
		{
			if (!bAutoPuzzle)
				return CALL_ORIGIN(LADNBFDOAMJHandler, _this, FMJLOIDBOKI, BHMGPLJEDCH);

			return TRUE;
		}
	}

	namespace RubikCubePuzzle
	{
		static void OnRotateFinishHandler(RPG::Client::Prop::RubikCubePuzzleCube* _this)
		{
			if (bAutoPuzzle && _this)
				_this->Order = 0;

			CALL_ORIGIN(OnRotateFinishHandler, _this);
		}
	}

	namespace RotatePillarPuzzle
	{
		static bool get_IsCompleteHandler(void* _this)
		{
			if (!bAutoPuzzle)
				return CALL_ORIGIN(get_IsCompleteHandler, _this);

			return TRUE;
		}
	}

	namespace InsertionPuzzle
	{
		static bool IsMatchItemHandler(void* _this, void* FBLKNKFEIFI)
		{
			if (!bAutoPuzzle)
				return CALL_ORIGIN(IsMatchItemHandler, _this, FBLKNKFEIFI);

			return TRUE;
		}
	}

	namespace OpticalIllusionPuzzle
	{
		static void UpdateHandler(RPG::Client::Prop::OpticalIllusionPuzzleBoard* _this)
		{
			CALL_ORIGIN(UpdateHandler, _this);

			if (bAutoPuzzle && _this->KDHABOGLJKC != RPG::Client::Prop::PuzzlePhase_FinishDelay && _this->KDHABOGLJKC != RPG::Client::Prop::PuzzlePhase_Finish)
				RPG::Client::Prop::OpticalIllusionPuzzleBoard::AANAJJJKMKM(_this, RPG::GameCore::PuzzleCustomEvent_OpticalIllusionFinish);
		}
	}

	namespace JigsawPuzzle
	{
		static bool CheckIsGameFinishHandler(void* _this)
		{
			if (!bAutoPuzzle)
				return CALL_ORIGIN(CheckIsGameFinishHandler, _this);

			return TRUE;
		}

	}

	void Render()
	{
		ImGui::BeginGroupPanel("Auto-Puzzle");

		ImGui::Checkbox("Enable", &bAutoPuzzle);

		ImGui::SameLine();

		ImGui::HelpMarker("In some puzzles you need to make the first move yourself.");

		ImGui::EndGroupPanel();
	}

	void Update()
	{

	}

	void Start()
	{
		CreateHook(RPG::Client::Prop::CablePuzzleBoard::LADNBFDOAMJ, CablePuzzle::LADNBFDOAMJHandler);

		CreateHook(RPG::Client::Prop::RubikCubePuzzleCube::OnRotateFinish, RubikCubePuzzle::OnRotateFinishHandler);
		CreateHook(RPG::Client::Prop::RotatePillarPuzzleFragment::get_IsComplete, RotatePillarPuzzle::get_IsCompleteHandler);
		CreateHook(RPG::Client::Prop::InsertionPuzzleItem::IsMatchItem, InsertionPuzzle::IsMatchItemHandler);

		CreateHook(RPG::Client::Prop::OpticalIllusionPuzzleBoard::Update, OpticalIllusionPuzzle::UpdateHandler);
		CreateHook(RPG::Client::Prop::JigsawPuzzleBoard::_CheckIsGameFinish, JigsawPuzzle::CheckIsGameFinishHandler);
	}
}