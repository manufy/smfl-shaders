
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <SFML/System.hpp>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

#define SHADER_FILENAME         "f3.frag"
#define VSHADER_FILENAME         "f1.vert"
#define SCREEN_HEIGHT = 768;
#define SCREEN_WIDTH = 1024;

int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1024, 768), "SFML window");

    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile(resourcePath() + "cute_image.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text text("Hello SFML", font, 50);
    text.setFillColor(sf::Color::Black);

    // Load a music to play
    sf::Music music;
    if (!music.openFromFile(resourcePath() + "nice_music.ogg")) {
        return EXIT_FAILURE;
    }
    
    // Check if shaders are available
      if (!sf::Shader::isAvailable())
      {
          std::cerr << "Shader are not available" << std::endl;
          return -1;
      }

      // Load shaders
      sf::Shader shader;
      if (!shader.loadFromFile(resourcePath() +SHADER_FILENAME, sf::Shader::Fragment))
      {
          std::cerr << "Error while shaders" << std::endl;
          return -1;
      }
    
    sf::Shader vshader;
    if (!vshader.loadFromFile(resourcePath() +VSHADER_FILENAME, sf::Shader::Vertex))
    {
        std::cerr << "Error while shaders" << std::endl;
        return -1;
    }


    // Play the music
    // music.play();
    
    sf::Clock time;
    int microsecondsInSecond = 1000000;
    unsigned int Seed = 10;
    float disp = 1.0;

    
    sf::VertexArray particles2(sf::Points, 10000);
    
    for (int i = 0; i < 10000; i++)
       {
         particles2[i].position = sf::Vector2f(rand() % 1024,rand() % 768);
           particles2[i].color = sf::Color::Yellow;
                
       }

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }
        
        
      
        
        // shader.setParameter,("time", time.getElapsedTime().asSeconds());
       
        shader.setUniform("resolution", sf::Vector2f(sprite.getTexture()->getSize().x, sprite.getTexture()->getSize().y));
     

        // Clear screen
        window.clear(sf::Color::Black);
        
        sf::VertexArray particles(sf::Points,1);
        particles[0].position = sf::Vector2f(10.f, 10.f);
        particles[0].color = sf::Color::Green;

        window.draw(particles);
        vshader.setUniform("time",disp);
        disp++;
        
        window.draw(particles2,&vshader);

             //  window.draw(particles,1000,sf::Points);

        // Draw the sprite
        //window.draw(sprite);
      //  window.draw(sprite,&shader);

        // Draw the string
        window.draw(text);
       // window.draw(particles,sf::Points);
        
        sf::Vertex point(sf::Vector2f(100, 100), sf::Color::Red);
        window.draw(&point, 1, sf::Points);
        
        
   //xs sf::Vertex vertex = sf::Vertex.new({10, 50}, SF::Color::Red, {100, 1 });
        //    window.draw(vertex);
        // Update the window
        window.display();
        
        //Print current aproximate fps
         std::string fps("fps: " + std::to_string((microsecondsInSecond / time.restart().asMicroseconds())));
         text.setString(fps);
    }

    return EXIT_SUCCESS;
}
