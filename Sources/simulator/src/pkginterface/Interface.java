/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pkginterface;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.net.SocketTimeoutException;
import java.net.UnknownHostException;
import org.newdawn.slick.AppGameContainer;
import org.newdawn.slick.SlickException;

/**
 *
 * @author Flavien Maillot <fmaillot@webcomputing.fr>
 */
public class Interface
{
	public static Thread t1;
	/**
	 * @param args the command line arguments
	 */
	public static void main(String[] args) throws SlickException, IOException
	{
		// TODO code application logic here
//		new AppGameContainer(new WindowGame(), 800, 600, false).start();
		Socket socket;
		BufferedReader in;
		PrintWriter out;
		
		WindowGame wingame = new WindowGame();

		BufferedReader entree = new BufferedReader(new InputStreamReader(System.in));
 		System.out.println("Veuillez saisir une adresse ip (127.0.0.1) : ");

		String addr = entree.readLine();
		System.out.println("Adresse : " + addr);

		System.out.println("Veuillez saisir un port (0000) : ");
		int port = Integer.parseInt(entree.readLine());
		System.out.println("port : " + port);
		
		try
		{

//			socket = new Socket("10.20.86.162", 4243); "10.20.86.154"
			socket = new Socket();
			socket.connect(new InetSocketAddress(addr, port), 1000);
			System.out.println("Demande de connexion");

			t1 = new Thread(new GameThread(wingame));
			t1.start();
//			new AppGameContainer(wingame, 800, 600, false).start();

			System.out.println("En attente du lancement complet de l'interface...");
			Thread.sleep(5000);
			in = new BufferedReader(new InputStreamReader(socket.getInputStream()));

			String message_distant;
			boolean active = true;
			while(active)
			{
//				Thread.sleep(500);
				System.out.println("Wait message...");
				message_distant = in.readLine();

				//Virer le pb a ju
				message_distant = message_distant.replace("\0", "");
				System.out.println(message_distant);
				System.out.println(message_distant.charAt(0));
				if (message_distant.length() >= 5)
				{
					if (message_distant.charAt(6) == 'l')
					{

						wingame.action(WindowGame.Act.LEFT);
					}
					else if (message_distant.charAt(6) == 'r')
					{
	//					System.out.println("right");
						wingame.action(WindowGame.Act.RIGHT);
					}
					else if (message_distant.charAt(6) == 'g')
					{
						wingame.action(WindowGame.Act.GO);
					}
					else if (message_distant.charAt(6) == 's')
					{
						wingame.action(WindowGame.Act.STOP);
					}
					
				}
//				System.out.println(message_distant);
			}
			socket.close();

		}
		catch (java.net.SocketTimeoutException e){
//			e.printStackTrace();
			System.err.println("Connexion timed out !");
		}
		catch (UnknownHostException e)
		{
			e.printStackTrace();
		}
		catch (IOException e)
		{

			e.printStackTrace();
		}
		catch (Exception e)
		{
			e.printStackTrace();
//			System.err.println("eeee");
		}
	}

}
