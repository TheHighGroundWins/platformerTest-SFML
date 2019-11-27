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
        playerRect.move(-2,0);
    }
}
void Player::moveRight()
{
    if(Keyboard::isKeyPressed(Keyboard::D))
    {
        playerRect.move(2,0);
    }
}
void Player::jump()
{
    if(Keyboard::isKeyPressed(Keyboard::W))
    {
        playerRect.move(0,-5);
        isJumping=true;
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
    if(playerRect.getPosition().y<resolution.y-200&&isJumping==false)
    {
        playerRect.move(0,gravity);
    }
    if(playerRect.getPosition().x>resolution.x-50)
    {
        playerRect.setPosition(lastX,lastY);
    }
    else if(playerRect.getPosition().x<0)
    {
        playerRect.setPosition(lastX,lastY);
    }
    else if(playerRect.getPosition().y>resolution.y-50)
    {
        playerRect.setPosition(lastX,lastY);
    }
    else if(playerRect.getPosition().y<0)
    {
        playerRect.setPosition(lastX,lastY);
    }
    else if(playerRect.getGlobalBounds().intersects(plat.getShape().getGlobalBounds()))
    {
        playerRect.setPosition(lastX,lastY);
        isJumping=true;
    }
    lastX=playerRect.getPosition().x;
    lastY=playerRect.getPosition().y;
}
