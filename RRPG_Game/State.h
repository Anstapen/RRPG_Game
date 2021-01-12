#pragma once
#include <string>
#include "olcPixelGameEngine.h"
#include "Layer.h"
#include "StateType.h"
#include "Event.h"

class Layer;

/**********************************************************************************************//**
 * \class	State
 *
 * \brief	This is the abstract state class, that every state should inherit from.
 *
 * \author	Anton
 * \date	12.01.2021
 **************************************************************************************************/

class State : public olc::PGEX
{

public:
	/** \brief	The type of the state. */
	StateType Type;
	/** \brief	Full pathname of the packing manager file */
	std::string sPackingManagerPath;

public:

	/**********************************************************************************************//**
	 * \fn	State::State(std::string name);
	 *
	 * \brief	Constructor for the State Class.
	 *
	 * \author	Anton
	 * \date	12.01.2021
	 *
	 * \param 	name	The type of the state.
	 **************************************************************************************************/

	State(StateType in_type);
	virtual ~State();

	/**********************************************************************************************//**
	 * \fn	virtual StateChanger State::Execute(float fElapsedTime) = 0;
	 *
	 * \brief	Execute function that has to be implemented by every child class. This function gets
	 * 			called every OnUserUpdate() function.
	 *
	 * \author	Anton
	 * \date	12.01.2021
	 *
	 * \param 	fElapsedTime	The elapsed time.
	 *
	 * \returns	A StateChanger.
	 **************************************************************************************************/

	virtual StateType Execute(float fElapsedTime) = 0;

	/**********************************************************************************************//**
	 * \fn	virtual bool State::Setup() = 0;
	 *
	 * \brief	This function is used to setup the state and gets called once at startup.
	 *
	 * \author	Anton
	 * \date	12.01.2021
	 *
	 * \returns	True if it succeeds, false if it fails.
	 **************************************************************************************************/

	virtual bool Setup() = 0;

	/**********************************************************************************************//**
	 * \fn	virtual void State::DrawContent(float fElapsedTime) = 0;
	 *
	 * \brief	This function is used to draw the state content on the screen every frame.
	 *
	 * \author	Anton
	 * \date	12.01.2021
	 *
	 * \param 	fElapsedTime	The elapsed time.
	 **************************************************************************************************/

	virtual void DrawContent(float fElapsedTime) = 0;


	/**********************************************************************************************//**
	 * \fn	virtual void State::OnEnable() = 0;
	 *
	 * \brief	This function gets called everytime the state is enabled.
	 *
	 * \author	Anton
	 * \date	12.01.2021
	 **************************************************************************************************/

	virtual void OnEnable() = 0;

	/**********************************************************************************************//**
	 * \fn	virtual void State::OnDisable() = 0;
	 *
	 * \brief	This function gets called everytime the state is disabled.
	 *
	 * \author	Anton
	 * \date	12.01.2021
	 **************************************************************************************************/

	virtual void OnDisable() = 0;

protected:
	/** \brief	This vector contains all the layers. */
	std::vector<std::shared_ptr<Layer>> Layers;
	/*\brief	This list contains all the events that were triggered by external states.*/
	std::shared_ptr<std::list<std::shared_ptr<Event>>> ExternalEvents;
};