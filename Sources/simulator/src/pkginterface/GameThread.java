/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pkginterface;

import java.util.logging.Level;
import java.util.logging.Logger;
import org.newdawn.slick.AppGameContainer;
import org.newdawn.slick.SlickException;

/**
 *
 * @author Flavien Maillot <fmaillot@webcomputing.fr>
 */
public class GameThread implements Runnable
{

	public WindowGame wingame;
	
	public GameThread(WindowGame w)
	{
		wingame = w;
	}
	
	@Override
	public void run()
	{
		try
		{
			System.out.println("pkginterface.GameThread.run()");
			new AppGameContainer(wingame, 800, 600, false).start();
			
			//throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
		}
		catch (SlickException ex)
		{
			Logger.getLogger(GameThread.class.getName()).log(Level.SEVERE, null, ex);
		}
	}
	
}
