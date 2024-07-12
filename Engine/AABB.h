#pragma once

/*
	AABB (Axis-Aligned Bounding Box) �� ���ĵ� ��� ����

	  +y
	  ^
	  |         +----------------------max
	  |         |                      |
	  |         |		 center        |
	  |	        |          +---------- |
	  |         |          |  extend.x |
	  |         |  extend.y|           |
	  |         min--------------------+
	--+------------------------------------> +x
   0,0
*/

// ->  AABB ���� �ٽ� ������ �غ����

class AABB
{
public:
	AABB() : m_Center{0}, m_Extend{0}{}
public:
	D2D1_VECTOR_2F m_Center; // �߾�
	D2D1_VECTOR_2F m_Extend; // x,y �� Ȯ�尪

	float minX = m_Center.x - m_Extend.x;
	float maxX = m_Center.x + m_Extend.x;
	float minY = m_Center.y - m_Extend.y;
	float maxY = m_Center.y + m_Extend.y;

	// �� �̰� �ƿ� ���� ���߰�
	AABB(const AABB&) = default;
	AABB& operator=(const AABB&) = default;
	AABB(AABB&&) = default;
	AABB& operator=(AABB&&) = default;
	~AABB() = default;

	void SetCenter(float x, float y) { m_Center = { x,y }; }
	void SetExtent(float x, float y) { m_Extend = { x,y }; }
	float GetMinX() { return minX; }
	float GetMaxX() { return maxX; }
	float GetMinY() { return minY; }
	float GetMaxY() { return maxY; }


	// other�� ��� ������ ���ߴ���?

	bool CheckIntersect(const AABB& other) const
	{
		// self min,max
		float BoxA_xmin = m_Center.x - m_Extend.x;
		float BoxA_xmax = m_Center.x + m_Extend.x;
		float BoxA_ymin = m_Center.y - m_Extend.y;
		float BoxA_ymax = m_Center.y + m_Extend.y;

		// other min,max
		float BoxB_xmin = other.m_Center.x - other.m_Extend.x;
		float BoxB_xmax = other.m_Center.x + other.m_Extend.x;
		float BoxB_ymin = other.m_Center.y - other.m_Extend.y;
		float BoxB_ymax = other.m_Center.y + other.m_Extend.y;

		// Check for no overlap conditions
		if (BoxA_xmax < BoxB_xmin ||  // �����ʿ� ������ ��ĥ���� ����
			BoxA_xmin > BoxB_xmax ||  // ���ʿ� ������ ��ĥ���� ����
			BoxA_ymax < BoxB_ymin ||  // �Ʒ��� ������ ��ĥ���� ����
			BoxA_ymin > BoxB_ymax)	  // ���� ������ ��ĥ���� ����
		{
			return false;
		}

		return true;
	}
};

