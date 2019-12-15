Player::Player(float x,float y,float X,float Y, Vector2f resolutionIn)
{
    resolution = resolutionIn;
    playerRect.setFillColor(Color(0,0,255));
    playerRect.setPosition(Vector2f(x,y));
    playerRect.setSize(Vector2f(X,Y));
    lastX=x;
    lastY=y;
}

void Player::moveLeft()
{
    if(Keyboard::isKeyPressed(Keyboard::A))
    {
        playerRect.move(-1.5,0);
        left=true;
    }
    else{
        left=false;
    }
}
void Player::moveRight()
{
    if(Keyboard::isKeyPressed(Keyboard::D))
    {
        playerRect.move(1.5,0);
        right=true;
    }
    else{
        right=false;
    }
}
void Player::jump()
{
    Time counterTime;


    if(Keyboard::isKeyPressed(Keyboard::W))
    {
        //gets the amount of time passed and adds to the total time
        Clock longPress;
        if(right||left)
        {
            playerRect.move(0,-1);
        }
        else{
            playerRect.move(0,-2);
        }

        isJumping=true;
        counterTime=longPress.getElapsedTime();
        totalPress+=counterTime;
    }
    if(totalPress.asMicroseconds()>200)
    {
        isJumping=false;
    }
}
void Player::movePlayer()
{
    moveLeft();
    moveRight();
    jump();
}
RectangleShape Player::getShape()
{
    return playerRect;
}
void Player::updatePlayer(Platform plat)
{
    movePlayer();
    if(playerRect.getPosition().y<resolution.y-150&&!isJumping)
    {
        playerRect.move(0,gravity);
    }
    if(playerRect.getPosition().x>resolution.x-100)
    {
        playerRect.setPosition(lastX,lastY);
    }
    else if(playerRect.getPosition().x<0)
    {
        playerRect.setPosition(lastX,lastY);
    }
    //checks if the player is on the floor or not
    else if(playerRect.getPosition().y>resolution.y-150)
    {
        isJumping=true;
        playerRect.setPosition(lastX,lastY);
        Time zeroTime;
        totalPress=zeroTime;
    }
    //prevents going through the floor
    else if(playerRect.getPosition().y<0)
    {
        playerRect.setPosition(lastX,lastY);

    }
    else if(playerRect.getGlobalBounds().intersects(plat.getShape().getGlobalBounds()))
    {
        isJumping=true;
        playerRect.setPosition(lastX,lastY);
        Time zeroTime;
        totalPress=zeroTime;

    }
    lastX=playerRect.getPosition().x;
    lastY=playerRect.getPosition().y;

}
