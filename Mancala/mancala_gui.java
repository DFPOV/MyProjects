import java.awt.Dimension;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

public class mancala_gui extends JFrame {
	
	static mancala_rules rules = new mancala_rules();
	
	static boolean key = false;
	static int x = 0;
	static boolean extrastones;
	static int player = 2;
	static int mode = 1;
	static int[] line = new int[14];
	static boolean p1round = true;
	static boolean p2round = false;
	static boolean end = false;
	static JScrollPane information = new JScrollPane();
	static JList<String> list= new JList<String>();
	static DefaultListModel Model = new DefaultListModel();
	static JFrame f2 = new JFrame();
	static JButton b0 = new JButton(); 
	static JButton b1 = new JButton(); 
	static JButton b2 = new JButton(); 
	static JButton b3 = new JButton(); 
	static JButton b4 = new JButton(); 
	static JButton b5 = new JButton(); 
	static JButton b7 = new JButton(); 
	static JButton b8 = new JButton(); 
	static JButton b9 = new JButton(); 
	static JButton b10 = new JButton(); 
	static JButton b11 = new JButton(); 
	static JButton b12 = new JButton(); 
	static JLabel l13 = new JLabel();
	static JLabel l6 = new JLabel();
	static int count;
	
	public void fillbuttons(int choice) {
		information.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
		f2.add(b0);
		f2.add(b1);
		f2.add(b2);
		f2.add(b3);
		f2.add(b4);
		f2.add(b5);
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
		
		b0.setBounds(350,350,100,100);  
		b0.addActionListener(new allbuttonlistener());
		b1.setBounds(450,350,100,100);
		b1.addActionListener(new allbuttonlistener());
		b2.setBounds(550,350,100,100);
		b2.addActionListener(new allbuttonlistener());
		b3.setBounds(650,350,100,100);  
		b3.addActionListener(new allbuttonlistener());
		b4.setBounds(750,350,100,100);  
		b4.addActionListener(new allbuttonlistener());
		b5.setBounds(850,350,100,100);
		b5.addActionListener(new allbuttonlistener());
		
		l13.setBounds(200,150,100,300);   
		l13.setFont(new Font(null,Font.PLAIN,20));
		l6.setBounds(1050,150,100,300);
		l6.setFont(new Font(null,Font.PLAIN,20));
		information.setBounds(350,475,600,300);
		information.setFont(new Font(null,Font.PLAIN,20));
		f2.setVisible(true);
		information.setViewportView(list);
		
		for (int i = 0; i < line.length; i++) {
			line[i] = choice;
		}
		
		line[6] = 0;
		line[13] = 0;
		
		Model.addElement("-");
		Model.addElement("Player1, it's your time to choose! Click a button.(lower buttons)");
	}
	
	static public void setgui(){
		b12.setText(String.valueOf(line[12]));
		b11.setText(String.valueOf(line[11]));
		b10.setText(String.valueOf(line[10]));
		b9.setText(String.valueOf(line[9]));
		b8.setText(String.valueOf(line[8]));
		b7.setText(String.valueOf(line[7]));
		
		b5.setText(String.valueOf(line[5]));
		b4.setText(String.valueOf(line[4]));
		b3.setText(String.valueOf(line[3]));
		b2.setText(String.valueOf(line[2]));
		b1.setText(String.valueOf(line[1]));
		b0.setText(String.valueOf(line[0]));
	
		l13.setText(String.valueOf(line[13]));
		l6.setText(String.valueOf(line[6]));
	}
	
	public static int guiplay() {
		//		
		boolean exist = true;
				
		int land = 0;
		
		if (p1round) {

			exist = rules.emptymove(line,x);
			player = 1;
			
			if (!exist) {
				Model.addElement("-");
				Model.addElement("Sorry you wasted your round.");
				p1round = false;
				p2round = true;
				return 0;
			}
			
			land = rules.setzero(line, x);
			setgui();
			
			p1round = false;
			
			p1round = rules.extrarule1(player,land);
			if (p1round) {
				Model.addElement("-");
				Model.addElement("Player1, you got an extra round!");
			}
			extrastones = rules.extrarule2(player,land,line);
			if (extrastones) {
				Model.addElement("-");
				Model.addElement("Someone's stones got stolen!");
			}
			
			setgui();
			if (!p1round)
			p2round = true;
		}
		
		else if (p2round) {
			exist = rules.emptymove(line,x);
			player = 2;
			
			if (!exist) {
				Model.addElement("-");
				Model.addElement("Sorry you wasted your round.");
				p2round = false;
				p1round = true;
				return 0;
			}
			
			land = rules.setzero(line, x);
			setgui();
			
			p2round = false;
			
			p2round = rules.extrarule1(player,land);
			if (p2round) {
				Model.addElement("-");
				Model.addElement("Player2, you got an extra round!");
			}
			
			extrastones = rules.extrarule2(player,land,line);
			if (extrastones) {
				Model.addElement("-");
				Model.addElement("Someone's stones got stolen!");
			}
			
			setgui();
			if (!p2round)
			p1round = true;
		}
		return 0;
	}
	
	public void theEnd() {
		if((line[0]==0 && line[1]==0 && line[2]==0 && line[3]==0 && line[4]==0 && line[5]==0) || (line[8]==0 && line[9]==0 && line[10]==0 && line[11]==0 && line[12]==0 && line[7]==0)) {
			end = true;
		}
		
		else {
			end = false;
		}
		
		if (end) {
			mancala_endphase guiend = new mancala_endphase();
			guiend.pass(line[6],line[13]);
			f2.dispose();
		}
	}
	
	class allbuttonlistener implements ActionListener{
		
		public void actionPerformed(ActionEvent e) {
			
			theEnd();
			
			count = 1;
			if (p1round) {

				if(e.getSource().equals(b5)){
					x = 5;
				}
			
				if(e.getSource().equals(b4)){
					x = 4;
				}
			
				if(e.getSource().equals(b3)){
					x = 3;
				}
			
				if(e.getSource().equals(b2)){
					x = 2;
				}
		
				if(e.getSource().equals(b1)){
					x = 1;
				}
		
				if(e.getSource().equals(b0)){
					x = 0;
				}
				
				if (e.getSource().equals(b7) || e.getSource().equals(b8) || e.getSource().equals(b9) || e.getSource().equals(b10) || e.getSource().equals(b11) || e.getSource().equals(b12) && p1round) {
					count = 0;
				}
				
				if (count == 1) {
					guiplay();
					theEnd();
					if (p2round) {
						Model.addElement("-");
						Model.addElement("Player2, it's your time to choose! Click a button.(upper buttons)");
					}
				}
			}

			if (p2round) {
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
				
				if (e.getSource().equals(b0) || e.getSource().equals(b1) || e.getSource().equals(b2) || e.getSource().equals(b3) || e.getSource().equals(b4) || e.getSource().equals(b5) && p2round) {
					count = 0;
				}
				
				if (count == 1) {
					guiplay();
					theEnd();
					if (p1round) {
						Model.addElement("-");
						Model.addElement("Player1, it's your time to choose! Click a button.(lower buttons)");
					}
				}
			}
		}
	}
}
