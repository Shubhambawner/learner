//import Game.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;
import java.text.*;
import java.util.*;
import javax.swing.*;



class gameChess implements ActionListener {

  Random random = new Random();
  JFrame frame = new JFrame();
  JPanel title_panel = new JPanel();
  JPanel title_panel2 = new JPanel();
  JPanel button_panel = new JPanel();
  JLabel textfield = new JLabel();
  JLabel textfield2 = new JLabel();
  JButton buttons[] = new JButton[65];
  DataOutputStream Dos;
  
  public boolean gameOver = false;
  public boolean enable = true;
  public int lastPlayed = -1;
  public int activePiecePosition = -1;
  public String[] Data = new String[65];
  public char playerSymbol;
  public char opponentSymbol;

  public gameChess( DataOutputStream dos, String n) {
    this.Dos = dos;

    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.setSize(800, 800);
    frame.getContentPane().setBackground(new Color(50, 50, 50));
    frame.setLayout(new BorderLayout());
    frame.setVisible(true);

    textfield.setBackground(new Color(25, 25, 25));
    textfield.setForeground(new Color(25, 255, 0));
    textfield.setFont(new Font("Ink Free", Font.BOLD, 75));
    textfield.setHorizontalAlignment(JLabel.CENTER);
    textfield.setText("Tic-Tac-Toe");
    textfield.setOpaque(true);

    textfield2.setBackground(new Color(255, 255, 255));
    textfield2.setForeground(new Color(255, 25, 0));
    textfield2.setFont(new Font("Ink Free", Font.BOLD, 75));
    textfield2.setHorizontalAlignment(JLabel.CENTER);
    textfield2.setText("You are playing as : " + n);
    textfield2.setOpaque(true);

    title_panel.setLayout(new GridLayout(1, 2));
    //title_panel.setBounds(0,0,800,100);
    title_panel2.setLayout(new GridLayout(1, 2));
    //title_panel2.setBounds(100,100,800,100);

    button_panel.setLayout(new GridLayout(8, 8));
    button_panel.setBackground(new Color(150, 150, 150));

    for (int i = 0; i < 64; i++) {
      buttons[i] = new JButton();
      button_panel.add(buttons[i]);
      buttons[i].setFont(new Font("MV Boli", Font.BOLD, 120));
      buttons[i].setFocusable(false);
      if((i%2 + (i/8))%2==0)
      buttons[i].setBackground(new Color(255, 255, 255));
      else
      buttons[i].setBackground(new Color(25, 25, 25));
      buttons[i].addActionListener(this);

      Data[i] = " ";
    }
    
    fillBoard();

    title_panel.add(textfield);
    title_panel2.add(textfield2);
    frame.add(title_panel, BorderLayout.NORTH);
    frame.add(title_panel2, BorderLayout.SOUTH);
    frame.add(button_panel);
    //firstTurn();
  }
  void fillBoard(){
    Data[0] = "0p";
    Data[63] = "1p";
    refresh();
  }

  

  public void move(int a, int b){ // from B to A
    if(validate(a,b)){
      Data[a] = Data[b];
      Data[b] = " ";

      refresh();
      System.out.println("----------------moved from "+b+" to "+a);
    }
  }

  boolean validate(int a, int b){ // from B to A
    return true;
  }

  void refresh(){
    for(int i =0; i<64;i++){
      buttons[i].setText(Data[i]);
    }
    textfield.setText("Current move of: "+ Data[64]);
  }

  public void actionPerformed(ActionEvent e) {
    for (int i = 0; i < 64; i++) {
      if (e.getSource() == buttons[i] && enable) {
        //System.out.println(buttons[i].getText()+"---"+buttons[i].getText().length());
        if (
          (buttons[i].getText().length() == 0 ||
          buttons[i].getText().charAt(0) == ' ') &&
          activePiecePosition!=-1
        ) {
          //System.out.println(" i ");

          move(i, activePiecePosition);
          Data[64] = opponentSymbol+"";
          refresh();

          this.enable = false;

          lastPlayed = i;
          String s = i + "";
          String s1 = activePiecePosition+"";
          try {
            this.Dos.writeUTF(s);
            this.Dos.writeUTF(s1);
          } catch (Exception eee) {
            eee.printStackTrace();
          }
          activePiecePosition=-1;
          
        }
        else if(buttons[i].getText().charAt(0) == playerSymbol){
          activePiecePosition = i;
          
          //System.out.println(i+" i "+ activePiecePosition);
          
          check();
        }
      }
    }
  }

  

  public void check(){
    //code to check
  }
  
}

public class Server {

  public static void main(String[] args) throws IOException {
    // server is listening on port 5056
    ServerSocket ss = new ServerSocket(5056);

    Socket s = null;

    try {
      System.out.println("-----------------------------");
      // socket object to receive incoming client requests
      s = ss.accept();

      System.out.println("A new client is connected : " + s);

      // obtaining input and out streams
      DataInputStream dis = new DataInputStream(s.getInputStream());
      DataOutputStream dos = new DataOutputStream(s.getOutputStream());

      
      gameChess boardPlayer = new gameChess(dos, "0");
      boardPlayer.playerSymbol = '0';
      boardPlayer.opponentSymbol = '1';
      boardPlayer.enable = true;

      String received;
      String received1;
      String toreturn;
      Scanner sc = new Scanner(System.in);

      while (true) {
        try {
          System.out.print("0, Your turn: ");

          if (boardPlayer.gameOver) {
            break;
          }

          System.out.print("wait...");

          // receive the answer from client
          // this will wait till server's board object writes to client, and client writes back to server
          received = dis.readUTF();
          received1 = dis.readUTF();

          System.out.println("1 has played: to " + received +" from " + received1);
          boardPlayer.move(Integer.parseInt(received), Integer.parseInt(received1));
          boardPlayer.Data[64] = boardPlayer.playerSymbol+"";
          boardPlayer.refresh();
          boardPlayer.enable = true;

          if (boardPlayer.gameOver) {
            break;
          }
        } catch (IOException e) {
          e.printStackTrace();
        }
      }
    } catch (Exception e) {
      s.close();
      e.printStackTrace();
    }
  }

  public static int toInteger(String j) {
    int t = 0;
    if (j.charAt(0)=='0') t+= 0;
    if (j.charAt(0)=='1') t+= 1;
    if (j.charAt(0)=='2') t+= 2;
    if (j.charAt(0)=='3') t+= 3;
    if (j.charAt(0)=='4') t+= 4;
    if (j.charAt(0)=='5') t+= 5;
    if (j.charAt(0)=='6') t+= 6;
    if (j.charAt(0)=='7') t+= 7;
    if (j.charAt(0)=='8') t+= 8;
    if (j.charAt(0)=='9') t+= 9;

    if(j.length()>1)
    {if (j.charAt(1)=='0') t+=10 * 0;
    if (j.charAt(1)=='1') t+=10 * 1;
    if (j.charAt(1)=='2') t+=10 * 2;
    if (j.charAt(1)=='3') t+=10 * 3;
    if (j.charAt(1)=='4') t+=10 * 4;
    if (j.charAt(1)=='5') t+=10 * 5;
    if (j.charAt(1)=='6') t+=10 * 6;
    if (j.charAt(1)=='7') t+=10 * 7;
    if (j.charAt(1)=='8') t+=10 * 8;
    if (j.charAt(1)=='9') t+=10 * 9;}

    //System.out.println("error:  please input value =< 8, >=0 ");
    return 0;
  }
}
