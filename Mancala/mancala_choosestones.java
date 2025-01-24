import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextArea;

public class mancala_choosestones implements ActionListener{
	static JButton b4 = new JButton("2"); 
	static JButton b5 = new JButton("3"); 
	static JButton b6 = new JButton("4"); 
	static JButton b7 = new JButton("5"); 
	static JFrame f1 = new JFrame();
	
	static JTextArea TA2 = new JTextArea(" How many stones do you want to see in each pit? " ,10,10);
	public mancala_choosestones() {
	
		b4.setBounds(450,200,100,50);  
		b4.addActionListener(this);		
		b5.setBounds(550,200,100,50);  
		b5.addActionListener(this);		
		b6.setBounds(650,200,100,50);  
		b6.addActionListener(this);		
		b7.setBounds(750,200,100,50);  
		b7.addActionListener(this);
		
		TA2.setFont(new Font("Serif", Font.ITALIC, 30));
		TA2.setOpaque(false);
	    TA2.setEditable(false);
	    TA2.setWrapStyleWord(false);
	    TA2.setLineWrap(true);
		TA2.setBounds(350,20,1000,100);  
		
		f1.add(b4);
		f1.add(b5);
		f1.add(b6);
		f1.add(b7);
		f1.add(TA2);
		
		f1.setSize(1980,1080);
		f1.setLayout(null);
		f1.setVisible(true);
		f1.getContentPane().setBackground(Color.LIGHT_GRAY);
		}
	
	public void actionPerformed(ActionEvent e) {
		
		int choice;
		if(e.getSource().equals(b4)){
			f1.dispose();
			choice = 2; 
			mancala_choosemode gui= new mancala_choosemode();
			mancala_startprepare.Pass(choice);
			}	
	
		if(e.getSource().equals(b5)){
			f1.dispose();
			choice = 3; 
			mancala_choosemode gui= new mancala_choosemode();
			mancala_startprepare.Pass(choice);
			}
		if(e.getSource().equals(b6)){
			f1.dispose();
			choice = 4; 
			mancala_choosemode gui= new mancala_choosemode();
			mancala_startprepare.Pass(choice);
			}
		if(e.getSource().equals(b7)){
			f1.dispose();
			choice = 5; 
			mancala_choosemode gui= new mancala_choosemode();
			mancala_startprepare.Pass(choice);
			}
	}
}