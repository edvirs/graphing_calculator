#include <SFML/Graphics.hpp>
#include <cmath>

float graph_sin(float A, float B, float C, float D, float x, sf::Vector2f central_point)
{
    float sin_value = (A * 50) * -sin(0.05 * B * (x - central_point.x - (C * 50) ) ) + central_point.y - (D * 50);
    return sin_value;
}

float graph_cos(float A, float B, float C, float D, float x, sf::Vector2f central_point)
{
    float cos_value = (A * 50) * -cos(0.05 * B * (x - central_point.x - (C * 50) ) ) + central_point.y - (D * 50);
    return cos_value;
}

int main()
{
    unsigned int displayWidth = 1920;
    unsigned int displayHeight = 1080;

    float A = 2;
    float B = 0.5;
    float C = 0;
    float D = 0;

    int function_to_be_used = 1;
    //sin -> 1 , cos -> 2


    sf::Vector2f central_point(float(displayWidth) / 2, float(displayHeight) / 2);

    sf::RenderWindow window(sf::VideoMode(displayWidth, displayHeight), "graph");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(5);

    sf::Vertex VerticalLine[] =
    {
        sf::Vertex(sf::Vector2f(central_point.x, 0)),
        sf::Vertex(sf::Vector2f(central_point.x, float(displayHeight)))
    };

    sf::Vertex HorizontalLine[] =
    {
        sf::Vertex(sf::Vector2f(0, central_point.y)),
        sf::Vertex(sf::Vector2f(float(displayWidth), central_point.y))
    };

    VerticalLine[0].color = sf::Color(250, 250, 250);
    VerticalLine[1].color = sf::Color(250, 250, 250);
    HorizontalLine[0].color = sf::Color(250, 250, 250);
    HorizontalLine[1].color = sf::Color(250, 250, 250);

    sf::Vertex net[2];
    net[0].color = sf::Color(30, 30, 30);
    net[1].color = sf::Color(30, 30, 30);

    sf::Vertex net2[2];
    net2[0].color = sf::Color(60, 60, 60);
    net2[1].color = sf::Color(60, 60, 60);


    sf::VertexArray graph(sf::LineStrip, 2);

    if (function_to_be_used == 1)
    {
        for (int x = -10; x < 5000; x++) {
            graph.append(sf::Vertex(sf::Vector2f(x, graph_sin(A, B, C, D, x, central_point))));
        }
    }
    else if (function_to_be_used == 2)
    {
        for (int x = -10; x < 5000; x++) {
            graph.append(sf::Vertex(sf::Vector2f(x, graph_cos(A, B, C, D, x, central_point))));
        }
    }


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        for (int i = int(central_point.y) + 50; i < displayHeight; i += 50)                         //drawing net
        {
            window.draw(net, 2, sf::Lines);
            net[0].position = sf::Vector2f(0, i);
            net[1].position = sf::Vector2f(float(displayWidth), i);
        }

        for (int i = int(central_point.y) - 50; i < displayHeight; i -= 50)
        {
            window.draw(net, 2, sf::Lines);
            net[0].position = sf::Vector2f(0, i);
            net[1].position = sf::Vector2f(float(displayWidth), i);
        }

        for (int i = int(central_point.x) + 50; i < displayWidth; i += 50)
        {
            window.draw(net, 2, sf::Lines);
            net[0].position = sf::Vector2f(i, 0);
            net[1].position = sf::Vector2f(i, float(displayHeight));
        }

        for (int i = int(central_point.x) - 50; i < displayWidth; i -= 50)
        {
            window.draw(net, 2, sf::Lines);
            net[0].position = sf::Vector2f(i, 0);
            net[1].position = sf::Vector2f(i, float(displayHeight));
        }

        for (int i = int(central_point.x) + 200; i < displayWidth; i += 200)                          //drawing net2
        {
            window.draw(net2, 2, sf::Lines);
            net2[0].position = sf::Vector2f(i, 0);
            net2[1].position = sf::Vector2f(i, float(displayHeight));
        }

        for (int i = int(central_point.x) - 200; i < displayWidth; i -= 200)
        {
            window.draw(net2, 2, sf::Lines);
            net2[0].position = sf::Vector2f(i, 0);
            net2[1].position = sf::Vector2f(i, float(displayHeight));
        }

        for (int i = int(central_point.y) + 200; i < displayHeight; i += 200)
        {
            window.draw(net2, 2, sf::Lines);
            net2[0].position = sf::Vector2f(0, i);
            net2[1].position = sf::Vector2f(float(displayWidth), i);
        }

        for (int i = int(central_point.y) - 200; i < displayHeight; i -= 200)
        {
            window.draw(net2, 2, sf::Lines);
            net2[0].position = sf::Vector2f(0, i);
            net2[1].position = sf::Vector2f(float(displayWidth), i);
        }

        window.draw(VerticalLine, 2, sf::Lines);
        window.draw(HorizontalLine, 2, sf::Lines);
        window.draw(graph);
        window.display();
    }
}
