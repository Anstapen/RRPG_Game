#include "SimplePoly.h"

SimplePoly::SimplePoly(olc::vf2d in_pos, std::vector<olc::vf2d> in_points) :
	GameObject(in_pos),
	rpoints(in_points),
	tpoints(in_points)
{
}

void SimplePoly::Draw(float fElapsedTime)
{
	olc::Pixel colour = this->Colliding ? olc::RED : olc::GREEN;
	for (int a = 0; a < this->tpoints.size(); a++) {
		int b = (a + 1) % this->tpoints.size();
		pge->DrawLine(this->tpoints[a], this->tpoints[b], colour);
	}
}

std::shared_ptr<Event> SimplePoly::Update(float fElapsedTime, std::shared_ptr<std::list<std::shared_ptr<Event>>> eventlist)
{
	/*Update*/
	for (int i = 0; i < this->rpoints.size(); i++) {
		this->tpoints[i] = this->rpoints[i] +this->CenterPosition;
	}
	return std::shared_ptr<Event>();
}

bool SimplePoly::CheckOverlapSAT(std::shared_ptr<SimplePoly> poly)
{
	/*Firstly check every edge*/
	for (int a = 0; a < this->tpoints.size(); a++) {
		int b = (a + 1) % this->tpoints.size();

		olc::vf2d axisProj = { -(this->tpoints[b].y - this->tpoints[a].y), (this->tpoints[b].x - this->tpoints[a].x) };

		float min_r1 = INFINITY, max_r1 = -INFINITY;

		for (int p = 0; p < this->tpoints.size(); p++) {
			float q = (this->tpoints[p].x * axisProj.x + this->tpoints[p].y * axisProj.y);
			min_r1 = std::min(min_r1, q);
			max_r1 = std::max(max_r1, q);
		}

		float min_r2 = INFINITY, max_r2 = -INFINITY;

		for (int p = 0; p < poly->tpoints.size(); p++) {
			float q = (poly->tpoints[p].x * axisProj.x + poly->tpoints[p].y * axisProj.y);
			min_r2 = std::min(min_r2, q);
			max_r2 = std::max(max_r2, q);
		}

		if (!(max_r2 >= min_r1 && max_r1 >= min_r2)) {
			return false;
		}


	}

	return true;
}
