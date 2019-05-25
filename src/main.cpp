
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
#include <cmath>
#include <iostream>

#include "../include/Collision.hpp"
#include "../include/GameEngine.hpp"
#include "../include/PlayState.hpp"
#include "../include/MainMenuState.hpp"

int main(int, char const**)
{
    GameEngine game(640, 360, "Arkanoid", "resources/icon.png", 60, true);

    game.textureMenager.addDir("resources");

    game.changeState(MainMenuState::instance());

    game.window.setSize(sf::Vector2u(1920, 1080));

    while( game.running() ){
        game.resetClock();
        game.handleEvents();
        game.update();
        game.render();
        game.setElapsedTime();
    }

    
    // srand(time(0));
    
    // sf::Clock clock;
    
    // // Create the main window
    // sf::RenderWindow window(sf::VideoMode(800, 600), "Arkanoid");
    // window.setFramerateLimit(60);
    // window.setVerticalSyncEnabled(false);

    // // Set the Icon
    // sf::Image icon;
    // if (!icon.loadFromFile("resources/icon.png")) {
    //     return EXIT_FAILURE;
    // }
    // window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // bool multi = true;
    // int player1Life = 3, player2Life = 3;;
    // std::string life1 = std::to_string(player1Life), life2 = std::to_string(player2Life);
    // int player1Points = 0, player2Points = 0;
    // std::string points1 = std::to_string(player1Points), points2 = std::to_string(player2Points);
    // bool whoHit = 0;
    
    // sf::Texture tBlock, tPaddle1, tPaddle2, tBackground, tBall;
    // tBlock.loadFromFile("resources/block01.png");
    // tPaddle1.loadFromFile("resources/paddle.png");
    // tPaddle2.loadFromFile("resources/paddle2.png");
    // //tBackground.loadFromFile(resourcePath( )+ "cute_image.jpg");
    // tBall.loadFromFile("resources/ball.png");
    
    // sf::Sprite sBackground(tBackground), sBall(tBall), sPaddle1(tPaddle1), sPaddle2(tPaddle2);
    // sPaddle1.setPosition(355, 500);
    // sPaddle2.setPosition(355, 50);
    // sBall.setPosition(395, 495);
    
    // sf::Sprite block[1000];
    // int n=0;
    // for(int i=0; i<13; i++){
    //     for (int j=0; j<8; j++) {
    //         if(rand()%2){
    //             block[n].setTexture(tBlock);
    //             block[n].setPosition(120+i*43, 170+j*20);
    //             n++;
    //         }
    //     }
    // }
    
    // sf::Font font;
    // if (!font.loadFromFile("resources/sansation.ttf")) {
    //     return EXIT_FAILURE;
    // }
    
    // float dx=rand()%5, dy;
    // dy = -sqrt(36-dx*dx);
    // rand()%2 ? dx=-dx : dx=dx;
    
    // // Start the game loop
    // while (window.isOpen()){
    //     // Process events
    //     sf::Event event;
    //     while (window.pollEvent(event)){
    //         // Close window: exit
    //         if (event.type == sf::Event::Closed) {
    //             window.close();
    //         }

    //         // Escape pressed: exit
    //         if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
    //             window.close();
    //         }
    //     }
        
    //     window.clear();
    //     window.draw(sBackground);
        
    //     std::cout << "Elapsed time since previous frame(miliseconds): " << clock.getElapsedTime().asMilliseconds() << std::endl;
    //     clock.restart();

    //     ///Ball
    //     float ballSpeed = dx*dx+dy*dy;
    //     sBall.move(dx,0);
    //     //std::cout<<dx<<" "<<dy<<std::endl;
    //     sf::Vector2f b = sBall.getPosition();
    //     if(b.x < 0 || b.x >= 800) dx = -dx;
    //     if(b.y < 0 || b.y >= 600) dy = -dy;
    //     for (int i=0; i<n; i++){
    //         if (Collision::PixelPerfectTest(sBall, block[i])){
    //             block[i].setPosition(-100, -100);
    //             dx>0 ? dx = -(dx+XChangeSpeed) : dx = -(dx-XChangeSpeed);
    //             dy>0 ?  dy = (dy+YChangeSpeed) : dy = (dy-YChangeSpeed);
    //             if(!whoHit)
    //                 player1Points += 100;
    //             else
    //                 player2Points += 100;
    //         }
    //     }
        
    //     sBall.move(0,dy);
        
    //     for (int i=0; i<n; i++){
    //         if (Collision::PixelPerfectTest(sBall, block[i])){
    //             block[i].setPosition(-100, -100);
    //             dy>0 ?  dy = -(dy+YChangeSpeed) : dy = -(dy-YChangeSpeed);
    //             dx>0 ? dx = (dx+XChangeSpeed) : dx = (dx-XChangeSpeed);
    //             if(!whoHit){
    //                 player1Points += 100;
    //                 points1 = std::to_string(player1Points);
    //             }
    //             else{
    //                 player2Points += 100;
    //                 points2 = std::to_string(player2Points);
    //             }
    //         }
    //     }
    //     //ball end
        
    //     //Player1
    //     sf::Text P1Life(life1, font, 40);
    //     P1Life.setFillColor(sf::Color::Yellow);
    //     P1Life.setPosition(0, 550);
        
    //     sf::Text P1Points(points1, font, 40);
    //     P1Points.setFillColor(sf::Color::Yellow);
    //     P1Points.setPosition(700, 550);
        
    //     window.draw(sPaddle1);

    //     sf::Vector2f paddle1Position = sPaddle1.getPosition();
    
    //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && paddle1Position.x < 690) sPaddle1.move(10,0);
    //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && paddle1Position.x > 0) sPaddle1.move(-10,0);
        
    //     if (Collision::PixelPerfectTest(sBall, sPaddle1)) {
    //         dx<=0 ? dx = -float( rand() % 5000 * 1.0 / 1000 ) : dx = float( rand() % 5000 * 1.0 / 1000 );
    //         dy = -sqrt(ballSpeed - dx*dx);
    //         //std::cout<<dx<<" "<<dy<<" "<<ballSpeed<<std::endl;
    //         whoHit = 0;
    //     }
        
    //     if(b.y >= 600){
    //         //std::cout<<"Collision"<<std::endl;
    //         --player1Life;
    //         if(player1Life > 0) {
    //             life1 = std::to_string(player1Life);
    //         }else{
    //             life1="Player 1 - Game over!";
    //             //dx=0; //Stop the ball
    //             //dy=0;
    //         }
    //     }
    //             //player1 end
        
    //     //Player 2
    //     if(multi){
            
    //         sf::Text P2Life(life2, font, 40);
    //         P2Life.setFillColor(sf::Color::Yellow);
            
    //         sf::Text P2Points(points2, font, 40);
    //         P2Points.setFillColor(sf::Color::Yellow);
    //         P2Points.setPosition(700, 0);
            
    //         window.draw(sPaddle2);
    //         sf::Vector2f paddle2Position = sPaddle2.getPosition();
            
    //         if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && paddle2Position.x < 690) sPaddle2.move(10,0);
    //         if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && paddle2Position.x > 0) sPaddle2.move(-10,0);
            
    //         if (Collision::PixelPerfectTest(sPaddle2, sBall)) {
    //             dx<=0 ? dx = -float(rand()%5000*1.0/1000) : dx=float(rand()%5000*1.0/1000);
    //             dy = sqrt(ballSpeed - dx*dx);
    //             //std::cout<<dx<<" "<<dy<<" "<<ballSpeed<<std::endl;
    //             whoHit = 1;
    //         }
            
    //         if(b.y <= 0){
    //             //std::cout<<"Collision"<<std::endl;
    //             --player2Life;
    //             if(player2Life > 0) {
    //                 life2 = std::to_string(player2Life);
    //             }else{
    //                 life2="Player 2 - Game over!";
    //                 //dx=0; //Stop the ball
    //                 //dy=0;
    //             }
    //         }
    //         window.draw(P2Life);
    //         window.draw(P2Points);
    //     }
    //     //player2 end
        
    //     window.draw(sBall);
    //     for(int i=0; i<n; i++){
    //         window.draw(block[i]);
    //     }
    //     window.draw(P1Life);
    //     window.draw(P1Points);
    //     window.display();
    // }
    

    // return EXIT_SUCCESS;
}
