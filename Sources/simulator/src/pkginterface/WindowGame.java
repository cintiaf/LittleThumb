/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pkginterface;

import org.newdawn.slick.BasicGame;
import org.newdawn.slick.GameContainer;
import org.newdawn.slick.Graphics;
import org.newdawn.slick.SlickException;
import org.newdawn.slick.Input;
import org.newdawn.slick.tiled.TiledMap;

import org.newdawn.slick.Animation;
import org.newdawn.slick.SpriteSheet;

import org.newdawn.slick.Color;

import org.newdawn.slick.Image;

import java.lang.Enum;


/**
 *
 * @author Flavien Maillot <fmaillot@webcomputing.fr>
 */
public class WindowGame extends BasicGame
{
	public enum Act
	{
		LEFT,
		UP,
		RIGHT,
		DOWN,
		GO,
		STOP
	}
	
	private GameContainer container;
	private TiledMap map;

	//attribut personnage
	private float x = 300, y = 300;
	private int direction = 2;
	private boolean moving = false;
	private Animation[] animations = new Animation[8];

	//attribut camera
	private float xCamera = x, yCamera = y;

	Act act = Act.DOWN;
	
	public WindowGame()
	{
		super("Lesson 1 :: WindowGame");
	}

	public void action(Act chx)
	{
		System.out.println("Check action");
		if (chx == Act.LEFT)
		{
			if (act.ordinal() - 1 < 0)
				act = Act.DOWN;
			else
				act = Act.values()[act.ordinal() - 1];
			this.updateDirection(act);
		}
		else if (chx == Act.RIGHT)
		{
			if (act.ordinal() + 1 > 3)
				act = Act.LEFT;
			else
				act = Act.values()[act.ordinal() + 1];
			this.updateDirection(act);
		}
		else if (chx == Act.GO)
		{
			System.out.println("Try action GO for : " + act);
			switch (act)
			{
				case LEFT :
					this.keyPressed(Input.KEY_LEFT, '0');
					break;
				case RIGHT :
					this.keyPressed(Input.KEY_RIGHT, '0');
					break;
				case UP :
					this.keyPressed(Input.KEY_UP, '0');
					break;
				case DOWN :
					this.keyPressed(Input.KEY_DOWN, '0');
					break;
			}
		}
		else if (chx == Act.STOP)
		{
			this.keyReleased(Input.KEY_UP, '0');
		}
	}
	
	@Override
	public void init(GameContainer gc) throws SlickException
	{
		//init le container
		this.container = gc;
		//init la map
		this.map = new TiledMap("resources/map/exemple-collision.tmx");

		//Charge le personnage
		SpriteSheet spriteSheet = new SpriteSheet("resources/sprites/character.png", 64, 64);
		Animation animation = new Animation();
		this.animations[0] = loadAnimation(spriteSheet, 0, 1, 0);
		this.animations[1] = loadAnimation(spriteSheet, 0, 1, 1);
		this.animations[2] = loadAnimation(spriteSheet, 0, 1, 2);
		this.animations[3] = loadAnimation(spriteSheet, 0, 1, 3);
		this.animations[4] = loadAnimation(spriteSheet, 1, 9, 0);
		this.animations[5] = loadAnimation(spriteSheet, 1, 9, 1);
		this.animations[6] = loadAnimation(spriteSheet, 1, 9, 2);
		this.animations[7] = loadAnimation(spriteSheet, 1, 9, 3);
	}

	private Animation loadAnimation(SpriteSheet spriteSheet, int startX, int endX, int y)
	{
		Animation animation = new Animation();
		for (int x = startX; x < endX; x++)
		{
			animation.addFrame(spriteSheet.getSprite(x, y), 100);
		}
		return animation;
	}

	@Override
	public void update(GameContainer gc, int i) throws SlickException
	{
		//gestion de la carte translation
		int w = container.getWidth() / 4;
		if (this.x > this.xCamera + w)
		{
			this.xCamera = this.x - w;
		}
		if (this.x < this.xCamera - w)
		{
			this.xCamera = this.x + w;
		}
		int h = container.getHeight() / 4;
		if (this.y > this.yCamera + h)
		{
			this.yCamera = this.y - h;
		}
		if (this.y < this.yCamera - h)
		{
			this.yCamera = this.y + h;
		}

		//gestion de la vitesse de déplacement
		if (this.moving)
		{
			float futurX = getFuturX(i);
			float futurY = getFuturY(i);
			boolean collision = isCollision(futurX, futurY);
			if (collision)
			{
				this.moving = false;
			}
			else
			{
				this.x = futurX;
				this.y = futurY;
			}
			/*switch (this.direction)
			{
				case 0:
					this.y -= .1f * i;
					break;
				case 1:
					this.x -= .1f * i;
					break;
				case 2:
					this.y += .1f * i;
					break;
				case 3:
					this.x += .1f * i;
					break;
			}*/
//			System.out.println("Robot position x[" + (int)x + "] y[" + (int)y + "]");
		}
	}

	private boolean isCollision(float x, float y)
	{
		int tileW = this.map.getTileWidth();
		int tileH = this.map.getTileHeight();
		int logicLayer = this.map.getLayerIndex("logic");
//		System.out.println("logicLayer=" + logicLayer);
		Image tile = this.map.getTileImage((int) x / tileW, (int) y / tileH, logicLayer);
		boolean collision = tile != null;
		if (collision)
		{
			Color color = tile.getColor((int) x % tileW, (int) y % tileH);
			collision = color.getAlpha() > 0;
		}
		return collision;
	}

	private float getFuturX(int delta)
	{
		float futurX = this.x;
		switch (this.direction)
		{
			case 1:
				futurX = this.x - .1f * delta;
				break;
			case 3:
				futurX = this.x + .1f * delta;
				break;
		}
		return futurX;
	}

	private float getFuturY(int delta)
	{
		float futurY = this.y;
		switch (this.direction)
		{
			case 0:
				futurY = this.y - .1f * delta;
				break;
			case 2:
				futurY = this.y + .1f * delta;
				break;
		}
		return futurY;
	}

	@Override
	public void render(GameContainer gc, Graphics grphcs) throws SlickException
	{
		//translation map
		grphcs.translate(container.getWidth() / 2 - (int) this.xCamera,
				container.getHeight() / 2 - (int) this.yCamera);

		this.map.render(0, 0, 0);
		this.map.render(0, 0, 1);
		this.map.render(0, 0, 2);

		//dessin d'une ombre sous le robot
		grphcs.setColor(new Color(0, 0, 0, .5f));
		grphcs.fillOval(x - 16, y - 8, 32, 16);
		//affiche l'animation du perso
		grphcs.drawAnimation(animations[direction + (moving ? 4 : 0)], x - 32, y - 60);
	
		this.map.render(0, 0, 3);
		this.map.render(0, 0, 4);
	}

	public  void updateDirection(Act key)
	{
		switch (key)
		{
			case UP:
				this.direction = 0;
				break;
			case LEFT:
				this.direction = 1;
				break;
			case DOWN:
				this.direction = 2;
				break;
			case RIGHT:
				this.direction = 3;
				break;
		}
	}
	
	@Override
	public void keyPressed(int key, char c)
	{
		switch (key)
		{
			case Input.KEY_UP:
				this.act = Act.UP;
				this.direction = 0;
				this.moving = true;
				break;
			case Input.KEY_LEFT:
				this.act = Act.LEFT;
				this.direction = 1;
				this.moving = true;
				break;
			case Input.KEY_DOWN:
				this.act = Act.DOWN;
				this.direction = 2;
				this.moving = true;
				break;
			case Input.KEY_RIGHT:
				this.act = Act.RIGHT;
				this.direction = 3;
				this.moving = true;
				break;
		}
	}

	@Override
	public void keyReleased(int key, char c)
	{
		if (Input.KEY_ESCAPE == key)
		{
			container.exit();
		}
		this.moving = false;

	}
}
