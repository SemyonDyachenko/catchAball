#ifndef LEVEL_H
#define LEVEL_H


#include "TinyXML/tinyxml.h"
#include <iostream>
#include <map>
#include <vector>
#include <string>

#include <SFML/Graphics.hpp>


struct Object
{
	int GetPropertyInt(std::string name);//номер свойства объекта в нашем списке
	float GetPropertyFloat(std::string name);
	std::string GetPropertyString(std::string name);
	std::string name;//объ€вили переменную name типа string
	std::string type;//а здесь переменную type типа string
	sf::Rect<float> rect;//тип Rect с нецелыми значени€ми
	std::map<std::string, std::string> properties;//создаЄм ассоциатиный массив. ключ - строковый тип, значение - строковый
	sf::Sprite sprite;//объ€вили спрайт
};
struct Layer//слои
{
	int opacity;//непрозрачность сло€
	std::vector<sf::Sprite> tiles;//закидываем в вектор тайлы
};
class Level//главный класс - уровень
{
public:
	bool LoadFromFile(std::string filename);//возвращает false если не получилось загрузить
	Object GetObject(std::string name);
	std::vector<Object> GetObjects(std::string name);//выдаем объект в наш уровень
	std::vector<Object> GetAllObjects();//выдаем все объекты в наш уровень
	void Draw(sf::RenderTarget * target);//рисуем в окно
	sf::Vector2i GetTileSize();//получаем размер тайла
private:
	int width, height, tileWidth, tileHeight;//в tmx файле width height в начале,затем размер тайла
	int firstTileID;//получаем айди первого тайла
	sf::Rect<float> drawingBounds;//размер части карты которую рисуем
	sf::Texture tilesetImage;//текстура карты
	std::vector<Object> objects;//массив типа ќбъекты, который мы создали
	std::vector<Layer> layers;
};
///////////////////////////////////////

#endif