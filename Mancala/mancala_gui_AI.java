import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;

import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JScrollPane;
import javax.swing.Timer;

public class mancala_gui_AI {

	static mancala_rules rules = new mancala_rules();
	
	static boolean key = false;
	static int x = 0;
	static boolean extrastones;
	static int mode = 1;
	static int[] line = new int[14];
	static boolean playerround = true;// player
	static boolean AIround = false;// AI
	static boolean end = false;
	static JScrollPane information = new JScrollPane();
	static JList<String> list= new JList<String>();
	static DefaultListModel Model = new DefaultListModel();
	static JFrame f2 = new JFrame();
	static JLabel l0 = new JLabel(); 
	static JLabel l1 = new JLabel(); 
	static JLabel l2 = new JLabel(); 
	static JLabel l3 = new JLabel(); 
	static JLabel l4 = new JLabel(); 
	static JLabel l5 = new JLabel(); 
	static JButton b7 = new JButton(); 
	static JButton b8 = new JButton(); 
	static JButton b9 = new JButton(); 
	static JButton b10 = new JButton(); 
	static JButton b11 = new JButton(); 
	static JButton b12 = new JButton(); 
	static JLabel l13 = new JLabel();
	static JLabel l6 = new JLabel();
	static Timer timer;
	
	
	public void fillbuttons(int choice) {
		information.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
		f2.add(l0);
		f2.add(l1);
		f2.add(l2);
		f2.add(l3);
		f2.add(l4);
		f2.add(l5);
		f2.add(b7);
		f2.add(b8);
		f2.add(b9);
		f2.add(b10);
		f2.add(b11);
		f2.add(b12);
		
		f2.add(l13);
		f2.add(l6);
		f2.add(information);
		
		f2.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f2.setSize(1980,1080);
		f2.setLayout(null);
		list.setModel(Model);
		
		b12.setBounds(350,200,100,100);  
		b12.addActionListener(new allbuttonlistener());
		b11.setBounds(450,200,100,100);
		b11.addActionListener(new allbuttonlistener());
		b10.setBounds(550,200,100,100);  
		b10.addActionListener(new allbuttonlistener());
		b9.setBounds(650,200,100,100);
		b9.addActionListener(new allbuttonlistener());
		b8.setBounds(750,200,100,100); 
		b8.addActionListener(new allbuttonlistener());
		b7.setBounds(850,200,100,100);
		b7.addActionListener(new allbuttonlistener());
		
		l0.setBounds(400,350,100,100);  
		l1.setBounds(500,350,100,100);
		l2.setBounds(600,350,100,100);
		l3.setBounds(700,350,100,100);  
		l4.setBounds(800,350,100,100);  
		l5.setBounds(900,350,100,100);
		
		l13.setBounds(200,150,100,300);   
		l13.setFont(new Font(null,Font.PLAIN,20));
		l6.setBounds(1050,150,100,300);
		l6.setFont(new Font(null,Font.PLAIN,20));
		information.setBounds(350,475,600,300);
		information.setFont(new Font(null,Font.PLAIN,20));
		f2.setVisible(true);
		information.setViewportView(list);
		
		timer = new Timer(1000, null);
		
		for (int i = 0; i < line.length; i++) {
			line[i] = choice;
		}
		
		line[6] = 0;
		line[13] = 0;
		
		Model.addElement("-");
		Model.addElement("Player2, it's your time to choose! Click a button.");
	}
	
	static public void setgui(){
		b12.setText(String.valueOf(line[12]));
		b11.setText(String.valueOf(line[11]));
		b10.setText(String.valueOf(line[10]));
		b9.setText(String.valueOf(line[9]));
		b8.setText(String.valueOf(line[8]));
		b7.setText(String.valueOf(line[7]));
		
		l5.setText(String.valueOf(line[5]));
		l4.setText(String.valueOf(line[4]));
		l3.setText(String.valueOf(line[3]));
		l2.setText(String.valueOf(line[2]));
		l1.setText(String.valueOf(line[1]));
		l0.setText(String.valueOf(line[0]));
	
		l13.setText(String.valueOf(line[13]));
		l6.setText(String.valueOf(line[6]));
	}
	
	public static int playeraction() {
		//		
		boolean exist = false;
				
		int land = 0;	
	
		exist = rules.emptymove(line,x);
			
		if (!exist) {
			Model.addElement("-");
			Model.addElement("Sorry you wasted your round.");
			playerround = false;
			AIround = true;
			return 0;
		}
			
		land = rules.setzero(line, x);
		setgui();
			
		playerround = false;
			
		playerround = rules.extrarule1(2,land);
		if (playerround) {
			Model.addElement("-");
			Model.addElement("Player2, you got an extra round!");
		}
			
		extrastones = rules.extrarule2(2,land,line);
		if (extrastones) {
			Model.addElement("-");
			Model.addElement("Someone's stones got stolen!");
		}
			
		setgui();
		if (!playerround) {
			AIround = true;
		}
		return 0;
	}
	public static void theEnd() {
		if((line[0]==0 && line[1]==0 && line[2]==0 && line[3]==0 && line[4]==0 && line[5]==0) || (line[8]==0 && line[9]==0 && line[10]==0 && line[11]==0 && line[12]==0 && line[7]==0)) {
			end = true;
		}
		
		else {
			end = false;
		}
		
		if (end) {
			mancala_endphase guiend = new mancala_endphase();
			guiend.pass(line[6], line[13]);
			f2.dispose();
		}
	}
	
	public static int AImove1() {
		Model.addElement("-");
		Model.addElement("It's AI's move now, let's see...");
		setgui();
		int pit = 0;
		int k = 0;
		
		// when AI indicate that move this pit can get extra round
		for (int i = 0; i < 6; i++) {
			if (line[i] + i == 6) {
				timer.start();
				k = i+1;
				Model.addElement("-");
				Model.addElement("AI: I'm going to choose " + k + " that is on my side.");
				setgui();
				pit = i;
				return pit;
			}
		}
		// if no extra round can be get, find a pit where AI can stole player's stone
		for (int a = 0; a < 6; a++) {
			int x = 0;
			
			x = line[a] + a;
			
			if (x > 13) {
				x -= 13;
			}
			if (x > 26) {
				x-=27;
			}
			
			if (line[x] == 0 && x < 6 && line[a] != 0) {
				timer.start();
				k = a+1;
				Model.addElement("-");
				Model.addElement("AI: I'm going to choose " + k + " that is on my side.");
				return a;
				}
			}
		
		for (int a = 0; a < 6; a++) {
			int land = line[a] + a;
			if (land < 6){
				if (line[12-land] != 0 && line[a] != 0) {
					timer.start();
					k = a + 1;
					Model.addElement("-");
					Model.addElement("AI: I'm going to choose " + k + " that is on my side.");
					return a;
				}
			}
		}
		// if nothing special can be trigger, random a number
		Random rand = new Random();
		int z = 0;
		int count = 0;
		do {
			z = rand.nextInt(6);
			count += 1;
			if (count == 20) {
				
				if (line[0] != 0) {
					return 0;
				}
				
				if (line[1] != 0) {
					return 1;
				}
				
				if (line[2] != 0) {
					return 2;
				}
				
				if (line[3] != 0) {
					return 3;
				}
				
				if (line[4] != 0) {
					return 4;
				}
				
				if (line[5] != 0) {
					return 5;
				}
				
				else {
					Model.addElement("-");
					Model.addElement("AI: Seems like this is my end.");
					return -1;
				}
			}
		}while(line[z] == 0);
		timer.start();
		k = z+1;
		Model.addElement("-");
		Model.addElement("AI: I'm going to choose " + k + " that is on my side.");
		return z;
	}
	
	public static boolean AImove2(int pit){
		int land = 0;
		
		if (pit == -1) {
			theEnd();
			AIround = false;
			return false;
		}
		
		// this is for AI, line [0 - 6]
		land = rules.setzero(line,pit);
		setgui();
		
		AIround = false;
		
		AIround = rules.extrarule1(1,land);
		if(AIround) {
			timer.start();
			Model.addElement("-");
			Model.addElement("AI got another round!");
		}
		
		extrastones = rules.extrarule2(1,land,line);
		if (extrastones) {
			timer.start();
			Model.addElement("-");
			Model.addElement("Someone's stones got stolen!");
		}
		
		setgui();

		if (!AIround)
		playerround = true;
				
		return false;
	}
	
	class allbuttonlistener implements ActionListener{
		
		public void actionPerformed(ActionEvent e) {
			
			if (playerround) {

				if(e.getSource().equals(b12)){
					x = 12;
				}
			
		
				if(e.getSource().equals(b11)){
					x = 11;
				}
			
				if(e.getSource().equals(b10)){
					x = 10;
				}
			
				if(e.getSource().equals(b9)){
					x = 9;
				}
		
				if(e.getSource().equals(b8)){
					x = 8;
				}
		
				if(e.getSource().equals(b7)){
					x = 7;
				}
				
				playeraction();
				
				if (playerround) {
					Model.addElement("-");
					Model.addElement("Player2, it's your time to choose! Click a button.");
				}
				theEnd();
				
				while(AIround) {
					int pit = AImove1();
					AImove2(pit);
					theEnd();
				}
			}
		}
	}
}
