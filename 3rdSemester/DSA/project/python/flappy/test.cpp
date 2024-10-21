#define DATA 1
#define TREENODE 1

#ifndef SFML
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#define SFML 1
#endif

#include <iostream>
#include <random>
#include <time.h>
#include "BinaryTreeVisualizer.hpp"

unsigned int FPSlimit = 60;

int MaxHeight = 720;
int MaxWidth = 1280;

int menuHeight = MaxHeight;
int menuWidth = MaxWidth;

int VisualizerHeight = MaxHeight;
int VisualizerWidth = 0;

float pan = 2.0f;
float panfactor = pan;
float zoomFactor = 1.0f;

sf::View camera(sf::FloatRect(0, 0, MaxWidth, MaxHeight));

void initialiseVisualiser(Visualizer* visualizer)
{
    visualizer->initialiseData();
}

void funcPan()
{
    sf::Vector2i mPos_old = sf::Vector2i(0, 0);
    sf::Vector2i mPos = sf::Vector2i(0, 0);
    mPos_old = sf::Mouse::getPosition();
    sf::sleep(sf::milliseconds(30));
    mPos = sf::Mouse::getPosition();
    float x = ((float)mPos_old.x - mPos.x) * pan;
    float y = ((float)mPos_old.y - mPos.y) * pan;
    sf::Vector2f pos(x, y);
    camera.move(pos.x, pos.y);
}

void ZoomWindow(float delta)
{

    camera.zoom(zoomFactor + (delta / 10.0f));
}

void renderfunc(sf::RenderWindow& window, Visualizer* visualizer)
{

    sf::Thread initialiseThread([&]()
        { initialiseVisualiser(visualizer); });

    initialiseThread.launch();

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        if (window.hasFocus())
        {
            if (event.type == sf::Event::MouseWheelScrolled)
            {
                sf::Thread zoomWindow(&ZoomWindow, event.mouseWheelScroll.delta);
                zoomWindow.launch();
                window.setView(camera);
            }
            else if (event.type == sf::Event::Resized)
            {
                // update the view to the new size of the window
                sf::FloatRect visibleArea(0.f, 0.f, window.getSize().x, window.getSize().y);
                window.setView(sf::View(visibleArea));
                MaxWidth = window.getSize().x;
                MaxHeight = window.getSize().y;
                camera.setSize(sf::Vector2f(MaxWidth, MaxHeight));
                visualizer->updateView(MaxWidth, MaxHeight);
            }

            else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Thread MousePan(&funcPan);
                MousePan.launch();
                window.setView(camera);
            }

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                initialiseThread.launch();
                sf::sleep(sf::milliseconds(250));
            }
        }

        window.clear(sf::Color(238, 238, 238));

        visualizer->visualize(&window);

        window.display();

        window.clear();
    }
}

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(MaxWidth, MaxHeight), "", sf::Style::Default, settings);
    window.setFramerateLimit(FPSlimit);

    // srand(time(0));

    // sf::RenderWindow renderWindow(sf::VideoMode(VisualizerWidth, VisualizerHeight), "", sf::Style::Default, settings);
    // renderWindow.setFramerateLimit(FPSlimit);

    // sf::RenderWindow MenuWindow(sf::VideoMode(menuWidth, menuHeight), "", sf::Style::Default, settings);
    // MenuWindow.setFramerateLimit(FPSlimit);

    BinaryTreeVisualizer* BTV = new BinaryTreeVisualizer();
    Visualizer* visualizer = BTV;

    // sf::Thread RenderThread([&]() {
    //	renderfunc(renderWindow, visualizer);
    //	});

    // while (window.isOpen()) {
    //	sf::Event event;
    //	while (window.pollEvent(event))
    //	{
    //		if (event.type == sf::Event::Closed) {
    //			renderWindow.close();
    //			window.close();
    //		}

    //	}
    //	// set the renderWindow and menue as its sub windows
    //
    //
    //	window.clear(sf::Color(238, 238, 238));

    //	visualizer->visualize(&window);

    //	window.display();

    sf::Thread initialiseThread([&]()
        { initialiseVisualiser(visualizer); });

    initialiseThread.launch();

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        if (window.hasFocus())
        {
            if (event.type == sf::Event::MouseWheelScrolled)
            {
                sf::Thread zoomWindow(&ZoomWindow, event.mouseWheelScroll.delta);
                zoomWindow.launch();
                window.setView(camera);
            }
            else if (event.type == sf::Event::Resized)
            {
                // update the view to the new size of the window
                sf::FloatRect visibleArea(0.f, 0.f, window.getSize().x, window.getSize().y);
                window.setView(sf::View(visibleArea));
                MaxWidth = window.getSize().x;
                MaxHeight = window.getSize().y;
                camera.setSize(sf::Vector2f(MaxWidth, MaxHeight));
                visualizer->updateView(MaxWidth, MaxHeight);
            }

            else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Thread MousePan(&funcPan);
                MousePan.launch();
                window.setView(camera);
            }

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                initialiseThread.launch();
            }
        }

        window.clear(sf::Color(238, 238, 238));

        visualizer->visualize(&window);

        window.display();

        window.clear();
    }

    return 0;
}