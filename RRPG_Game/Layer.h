#pragma once
#include "GameObject.h"
#include "olcPixelGameEngine.h"
#include <memory>
#include "LayerPM.h"
#include "Event.h"
#include "State.h"
#include "StateType.h"
#include "PackingManager.h"

class LayerPM;
class State;

/**********************************************************************************************//**
 * \class	Layer
 *
 * \brief	Maybe the most important class of the whole game. The layer class is designed as a
 * 			container that holds objects, updates the behavior of them and draws them on the
 * 			screen. At startup, the layer is packed by a Packing Manager. This PM creates all the
 * 			default objects and sets their behavior.
 *
 * \author	Anton
 * \date	13.01.2021
 **************************************************************************************************/

class Layer : public olc::PGEX
{
public:

	/**********************************************************************************************//**
	 * \fn	Layer::Layer( int layerid, PackingManager::PackingStyle pack = PackingManager::PackingStyle::DEFAULT, std::list<std::shared_ptr<GameObject>> objects = std::list<std::shared_ptr<GameObject>>() );
	 *
	 * \brief	Constructor of the Layer Class. The layer_id has to be provided, it represents the
	 * 			PGE layer that it gets drawn on.
	 *
	 * \author	Anton
	 * \date	13.01.2021
	 *
	 * \param 	layerid	The layerid, created by CreateLayer().
	 * \param 	pack   	(Optional) An optional packing style.
	 * \param 	objects	(Optional) An optional list of objject that get added to the layer before the
	 * 					packing manager does anything.
	 **************************************************************************************************/

	Layer(
		int layerid,
		PackingManager::PackingStyle pack = PackingManager::PackingStyle::DEFAULT,
		std::list<std::shared_ptr<GameObject>> objects = std::list<std::shared_ptr<GameObject>>()
	);

	/**********************************************************************************************//**
	 * \fn	virtual void Layer::Setup() = 0;
	 *
	 * \brief	This function gets invoked after the Packing Manager added the required objects. It
	 * 			is used to setup any game mechanic related stuff.
	 *
	 * \author	Anton
	 * \date	13.01.2021
	 **************************************************************************************************/

	virtual void Setup() = 0;

	/**********************************************************************************************//**
	 * \fn	void Layer::Draw(float fElapsedTime);
	 *
	 * \brief	Draws its contents on the screen and ensures that the correct drawing target is
	 * 			selected.
	 *
	 * \author	Anton
	 * \date	13.01.2021
	 *
	 * \param 	fElapsedTime	The elapsed time.
	 **************************************************************************************************/

	void Draw(float fElapsedTime);

	/**********************************************************************************************//**
	 * \fn	virtual StateType Layer::Update(float fElapsedTime, std::shared_ptr<std::list<std::shared_ptr<Event>>> eventlist) = 0;
	 *
	 * \brief	Updates the layer. this function gets called every frame.
	 *
	 * \author	Anton
	 * \date	13.01.2021
	 *
	 * \param 	fElapsedTime	The elapsed time.
	 * \param 	eventlist   	A list of events that are specifically for the layer.
	 *
	 * \returns	Returns the state that the game should change to, default should be NO_CHANGE.
	 **************************************************************************************************/

	virtual StateType Update(float fElapsedTime, std::shared_ptr<std::list<std::shared_ptr<Event>>> eventlist) = 0;

	/**********************************************************************************************//**
	 * \fn	virtual std::shared_ptr<LayerPM> Layer::GetLayerPM() = 0;
	 *
	 * \brief	This function should provide a correct Packaging Manager for the Layer.
	 *
	 * \author	Anton
	 * \date	13.01.2021
	 *
	 * \returns	The correct Packing Manager for the Layer.
	 **************************************************************************************************/

	virtual std::shared_ptr<LayerPM> GetLayerPM() = 0;

	/**********************************************************************************************//**
	 * \fn	void Layer::AddObject(std::shared_ptr<GameObject> obj);
	 *
	 * \brief	Public interface for other classes to add an object to the layer.
	 *
	 * \author	Anton
	 * \date	13.01.2021
	 *
	 * \param 	obj	The object.
	 **************************************************************************************************/

	void AddObject(std::shared_ptr<GameObject> obj);

	/**********************************************************************************************//**
	 * \fn	bool Layer::EnableLayer();
	 *
	 * \brief	This function is called to enable the layer. Internally, OnEnable() gets called where
	 * 			the developer can implement anything that has to be executed when the layer is
	 * 			enabled.
	 *
	 * \author	Anton
	 * \date	13.01.2021
	 *
	 * \returns	Returns true, if the layer was enabled successfully, otherwise it returns false.
	 **************************************************************************************************/

	bool EnableLayer();

	/**********************************************************************************************//**
	 * \fn	bool Layer::DisableLayer();
	 *
	 * \brief	This function behaves the same as EnableLayer(), only that it calls OnDisable().
	 *
	 * \author	Anton
	 * \date	13.01.2021
	 *
	 * \returns	Returns true, if the layer was disabled successfully, otherwise it returns false.
	 **************************************************************************************************/

	bool DisableLayer();
protected:

	/**********************************************************************************************//**
	 * \fn	virtual bool Layer::OnEnable() = 0;
	 *
	 * \brief	Deleted function that has to be implemented by a child class. It gets called when the
	 * 			layer is enabled.
	 *
	 * \author	Anton
	 * \date	13.01.2021
	 *
	 * \returns	True if it succeeds, false if it fails.
	 **************************************************************************************************/

	virtual bool OnEnable() = 0;

	/**********************************************************************************************//**
	 * \fn	virtual bool Layer::OnDisable() = 0;
	 *
	 * \brief	Deleted function that has to be implemented by a child class. It gets called when the
	 * 			layer is disabled.
	 *
	 * \author	Anton
	 * \date	13.01.2021
	 *
	 * \returns	True if it succeeds, false if it fails.
	 **************************************************************************************************/

	virtual bool OnDisable() = 0;

	/**********************************************************************************************//**
	 * \fn	virtual void Layer::OnDraw(float fElapsedTime) = 0;
	 *
	 * \brief	This function gets called by Draw() after the correct drawing target is selected.
	 * 			This function should be used to draw the contents of the layer.
	 *
	 * \author	Anton
	 * \date	13.01.2021
	 *
	 * \param 	fElapsedTime	The elapsed time.
	 **************************************************************************************************/

	virtual void OnDraw(float fElapsedTime) = 0;

	/**********************************************************************************************//**
	 * \fn	virtual StateType Layer::HandleEvents() = 0;
	 *
	 * \brief	This function should handle any events left in the eventlist, after the objects were
	 * 			updated.
	 *
	 * \author	Anton
	 * \date	13.01.2021
	 *
	 * \returns	The state the should be enabled, if the satate hould not be changed, return NO_CHANGE.
	 **************************************************************************************************/

	virtual StateType HandleEvents() = 0;
	/** \brief	Determines of the layer is currently enabled or disabled. */
	bool Enabled;
	/** \brief	The layer id that represents the drawing target. */
	const int ID;
	/** \brief	The style in which the layer gets packed. */
	PackingManager::PackingStyle Packing = PackingManager::PackingStyle::DEFAULT;
	/** \brief	The list of objects that the layer conatins. */
	std::list<std::shared_ptr<GameObject>> AllObjects;
	/*\brief	The list of internal events that need to be handled by the layer itself or the by its
	* objects.*/
	std::shared_ptr<std::list<std::shared_ptr<Event>>> InternalEvents;
};