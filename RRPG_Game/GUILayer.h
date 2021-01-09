#pragma once
#include "Layer.h"
#include "LayerPM.h"
#include "Cursor.h"
class GUILayer :
	public Layer
{
	friend class GUILayerPM;
public:
	GUILayer(
		int layerid,
		PackingManager::PackingStyle pack = PackingManager::PackingStyle::DEFAULT,
		std::list<std::shared_ptr<GameObject>> objects = std::list<std::shared_ptr<GameObject>>()
	);
	virtual void Setup() override;
	virtual StateChanger Update(float FElapsedTime, std::shared_ptr<std::list<std::shared_ptr<Event>>> eventlist) override;
	
	virtual std::shared_ptr<LayerPM> GetLayerPM() override;
	void AddCursor(std::shared_ptr<Cursor> in_cursor);

protected:
	virtual bool OnEnable() override;
	virtual bool OnDisable() override;
	virtual void OnDraw(float fElapsedTime) override;
	virtual StateChanger HandleEvents() override;
	/*A GUI Layer is the only Layer that has a Cursor that it can draw*/
	void DrawCursor(float fElapsedTime);
	void UpdateCursor(float fElapsedTime);
	std::shared_ptr<Cursor> cursor;
};