#include "InspectorWindow.h"
#include "../../Window/Engine/EngineWindow.h"
#include "../../PrimaryType/Vector2/Vector2.h"
#include "../../Selection/Selection.h"

#pragma region constructor
Engine::Editor::InspectorWindow::InspectorWindow() : super("Inspector")
{
	const int _width = Window::EngineWindow::Instance()->Width();
	const int _height = Window::EngineWindow::Instance()->Height();
	shape = sf::RectangleShape(PrimaryType::Vector2(300, _height));
	shape.setFillColor(sf::Color(50, 50, 50, 255));
	SetPosition(PrimaryType::Vector2(_width - 300, 25));
	Selection::OnSelectionChanged.AddDynamic(this, &InspectorWindow::OnSelectionchanged);
}
Engine::Editor::InspectorWindow::InspectorWindow(const InspectorWindow& _copy) = default;
Engine::Editor::InspectorWindow::~InspectorWindow()
{
	Selection::OnSelectionChanged.RemoveDynamic(this, &InspectorWindow::OnSelectionchanged);
}
#pragma endregion

#pragma region methods
void Engine::Editor::InspectorWindow::OnSelectionchanged(Object* _o)
{
	//TODO if object to edit not nullptr serialize this
	//TODO else set Object to edit
	//TODO draw all properties of object
}
#pragma endregion
