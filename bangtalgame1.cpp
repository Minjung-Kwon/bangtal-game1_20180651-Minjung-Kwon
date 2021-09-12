#include <bangtal>            // ��Ż ���̺귯���� ����ϱ� ���� ��� �����ϱ�
using namespace bangtal;      // bangtal ���� �����̽��� ����Ѵٰ� �����ϱ�


bool door1_mouseCallback(ObjectPtr object, int x, int y, MouseAction action)
{
	endGame();
	return true;
}



int main()
{
	auto room1 = Scene::create("��1", "Images/���-1.png");
	auto room2 = Scene::create("��2", "Images/���-2.png");


	auto door1 = Object::create("Images/��-������-����.png", room1, 800, 270);
	auto closed1 = true;


	auto key = Object::create("Images/����.png", room1, 600, 150);
	key->setScale(0.3f);
	key->setOnMouseCallback([&](auto object, auto x, auto y, auto action) -> bool {
		object->pick();
		return true;
	});


	auto flowerpot_moved = false;
	auto flowerpot = Object::create("Images/ȭ��.png", room1, 550, 150);
	flowerpot->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (!flowerpot_moved) {
			if (action == MouseAction::MOUSE_DRAG_LEFT) {
				object->locate(room1, 450, 150);
				flowerpot_moved = true;
			}
			else if (action == MouseAction::MOUSE_DRAG_RIGHT) {
				object->locate(room1, 650, 150);
				flowerpot_moved = true;
			}
		}
		return true;
	});


	door1->setOnMouseCallback([&](auto object, auto x, auto y, auto action) -> bool {
		if (closed1) {
			if (key->isHanded()) {
				object->setImage("Images/��-������-����.png");
				closed1 = false;
			}
			else {
				showMessage("���谡 �ʿ���!");
			}
		}
		else {
			room2->enter();
		}
		return true;
	});


	auto door2 = Object::create("Images/��-����-����.png", room2, 320, 270);
	door2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		room1->enter();
		return true;
	});





	//�ι�° �濡�� �ι�° �� ������ ���� �����ϱ�
	auto door3 = Object::create("Images/��-������-����.png", room2, 900, 270);
	auto closed2 = true;

	door3->setOnMouseCallback([&](auto object, auto x, auto y, auto action)-> bool {
		if (closed2) {
			if (key->isHanded()) {
				object->setImage("Images/��-������-����.png");
				closed2 = false;
			}
		}
		else {
			endGame();
		}
		return 0;
	});




	//å�� �̵���Ű��
	auto bookshelter_moved = false;
	auto bookshelter = Object::create("Images/å��-������.png", room2, 850, 200);
	bookshelter->setScale(0.16f);
	bookshelter->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (!bookshelter_moved) {
			if (action == MouseAction::MOUSE_DRAG_LEFT) {
				object->locate(room2, 570, 210);
				bookshelter_moved = true;
			}
			else if (action == MouseAction::MOUSE_DRAG_RIGHT) {
				object->locate(room2, 1000, 180);
				bookshelter_moved = true;
			}
		}
		return true;
	});




	startGame(room1);
	return 0;

}
