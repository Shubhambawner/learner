// Java implementation for a client
// Save file as Client.java

import java.io.*;
import java.net.*;
import java.util.Scanner;

// Client class
public class Client
{
		public static String b = "\n  0 |  1 | 2  \n----|----|----\n  3 |  4 | 5  \n----|----|----\n  6 |  7 | 8  \n";

	public static void main(String[] args) throws IOException
	{
		try
		{
			Scanner scn = new Scanner(System.in);
			
			// getting localhost ip
			InetAddress ip = InetAddress.getByName("localhost");
	
			// establish the connection with server port 5056
			Socket s = new Socket(ip, 5056);
	
			// obtaining input and out streams
			DataInputStream dis = new DataInputStream(s.getInputStream());
			DataOutputStream dos = new DataOutputStream(s.getOutputStream());
	
			// the following loop performs the exchange of
			// information between client and client handler
			while (true)
			{ 	System.out.print("wait...");
				String j = dis.readUTF();
				if(j.charAt(0)=='_'){
					System.out.println(j);
				}
				System.out.println("X has played: "+j);

				System.out.println(gs('X',j.charAt(0) ) );

				System.out.print("O, Your turn: ");
				String tosend = scn.nextLine();
				dos.writeUTF(tosend);
				System.out.println(gs('O',tosend.charAt(0)));
				
				// If client sends exit,close this connection
				// and then break from the while loop
				if(tosend=="-1")
				{
					System.out.println("Closing this connection : " + s);
					s.close();
					System.out.println("Connection closed");
					break;
				}
				
				// printing date or time as requested by client
				//String received = dis.readUTF();
				//System.out.println(received);
			}
			
			// closing resources
			scn.close();
			dis.close();
			dos.close();
		}catch(Exception e){
			e.printStackTrace();
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
