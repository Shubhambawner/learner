// Java implementation of Server side
// It contains two classes : Server and ClientHandler
// Save file as Server.java

import java.io.*;
import java.text.*;
import java.util.*;
import java.net.*;

// Server class
public class Server
{
	public static String b = "\n  0 |  1 | 2  \n----|----|----\n  3 |  4 | 5  \n----|----|----\n  6 |  7 | 8  \n";

	public static void main(String[] args) throws IOException
	{
		// server is listening on port 5056
		ServerSocket ss = new ServerSocket(5056);

		DateFormat fordate = new SimpleDateFormat("yyyy/MM/dd");
		DateFormat fortime = new SimpleDateFormat("hh:mm:ss");

		//String b = "\n  0 |  1 | 2  \n----|----|----\n  3 |  4 | 5  \n----|----|----\n  6 |  7 | 8  \n";
		
		// running infinite loop for getting
		// client request
		while (true)
		{
			Socket s = null;
			
			try
			{
				System.out.println("-----------------------------");
				// socket object to receive incoming client requests
				s = ss.accept();
				
				System.out.println("A new client is connected : " + s);
				
				// obtaining input and out streams
				DataInputStream dis = new DataInputStream(s.getInputStream());
				DataOutputStream dos = new DataOutputStream(s.getOutputStream());
				
				System.out.println("A client player has connected.U have to make first move: ");
				System.out.println("The game board is: "+b);
		

				// create a new thread object
				//Thread t = new ClientHandler(s, dis, dos);

				// Invoking the start() method
				//t.start();

				//--
				String received;
				String toreturn;
				Scanner sc = new Scanner(System.in);
				int[] arr = {10,10,10,10,10,10,10,10,10,100}; 

				while (true)
				{
					try {
						System.out.print("X, Your turn: ");

						String consoleIP = sc.nextLine();
						// 
						//
						arr[toInteger(consoleIP)] = 1;
						
						if(win(arr)>=0){
							if(win(arr)==1){ 
								dos.writeUTF("_Server has won, U loose\n");
								System.out.println(b+ "\nU have won\n");}
							if(win(arr)==0){ 
								 dos.writeUTF("_U have won\n");
								 System.out.println(b+ "Client has won, U loose\n");}
							break;
						}
						System.out.println(gs('X',consoleIP.charAt(0) ));
						dos.writeUTF(consoleIP);
						System.out.print("wait...");

						// receive the answer from client
						received = dis.readUTF();
						
						
						if(toInteger(consoleIP)==-1)
						{
							System.out.println("Client  sends exit...");
							System.out.println("Closing this connection.");
							System.out.println("Connection closed");
							break;
						}

						System.out.println("O has played: "+received);
						arr[toInteger(received)] = 0;
						System.out.println(gs('O',received.charAt(0) ));

						if(win(arr)>=0){
							if(win(arr)==1){ 
								dos.writeUTF("Server has won, U loose\n");
								System.out.println("U have won\n");}
							if(win(arr)==0){ 
								 dos.writeUTF("U have won\n");
								 System.out.println("Client has won, U loose\n");}
							break;
						}
						
						// creating Date object
						//Date date = new Date();
						
						// write on output stream based on the
						// answer from the client

						
						
					} catch (IOException e) {
						e.printStackTrace();
					}
				}
				
			}
			catch (Exception e){
				s.close();
				e.printStackTrace();
			}
		}
	}

	public static int toInteger(String j){
		if(j.equals("0")) return 0;
		if(j.equals("1")) return 1;
		if(j.equals("2")) return 2;
		if(j.equals("3")) return 3;
		if(j.equals("4")) return 4;
		if(j.equals("5")) return 5;
		if(j.equals("6")) return 6;
		if(j.equals("7")) return 7;
		if(j.equals("8")) return 8;
		
		//System.out.println("error:  please input value =< 8, >=0 ");
		return 9;
	}

	public static int win(int[] board){
		
        for (int a = 0; a < 8; a++) {
			int line = 0;

			switch (a) {
				case 0:
					line = board[0] + board[1] + board[2];
					break;
				case 1:
					line = board[3] + board[4] + board[5];
					break;
				case 2:
					line = board[6] + board[7] + board[8];
					break;
				case 3:
					line = board[0] + board[3] + board[6];
					break;
				case 4:
					line = board[1] + board[4] + board[7];
					break;
				case 5:
					line = board[2] + board[5] + board[8];
					break;
				case 6:
					line = board[0] + board[4] + board[8];
					break;
				case 7:
					line = board[2] + board[4] + board[6];
					break;
			}
			//For X winner
			if (line==3) {
				return 1;
			}
				
			// For O winner
			else if (line==0) {
				return 0;
			}
		}
        
		return -1;
	}

	public static String gs(char k, char n){
		String h = "";
		//String b = "\n  0 |  1 | 2  \n----|----|----\n  3 |  4 | 5  \n----|----|----\n  6 |  7 | 8  \n";
		for(int i = 0; i< b.length(); i++){
			if(b.charAt(i)==n){
				h+=k;
			}else{
				h+=b.charAt(i);
			}
		}
		b = h;

		String hh = "";
		for(int i = 0; i< b.length(); i++){
			if(toInteger(b.charAt(i)+"")!=9){
				hh+=" ";
			}else{
				hh+=b.charAt(i);
			}
		}
		
		return hh; 
	}
}


//"  0 |  1 | 2  \n----|----|----\n  3 |  4 | 5  \n----|----|----\n  6 |  7 | 8  \n"
 