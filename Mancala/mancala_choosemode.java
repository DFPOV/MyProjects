import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;

import javax.swing.JTextArea;

public class mancala_choosemode implements ActionListener{
	

	static  JFrame f1 = new JFrame();
	static JTextArea TA1 = new JTextArea("Choose" ,10,10);
	static JButton b1=new JButton("AI"); 
	static JButton b2=new JButton("Human"); 
	static JButton b3=new JButton("Back"); 

	public mancala_choosemode() {
		// set the game mode
		b1.setBounds(700,450,100,50);  
		b1.addActionListener(this);	
		b2.setBounds(500,450,100,50);  
		b2.addActionListener(this);	
		b3.setBounds(600,550,100,50);  
		b3.addActionListener(this);	
		
		TA1.setFont(new Font("Serif", Font.ITALIC, 50));
		TA1.setOpaque(false);
	    TA1.setEditable(false);
	    TA1.setWrapStyleWord(false);
	    TA1.setLineWrap(true);
		TA1.setBounds(580,350,200,100);  
		
		f1.add(b1);
		f1.add(b2);
		f1.add(b3);	
	    f1.add(TA1);

		f1.setSize(1980,1080);
		f1.setLayout(null);
		f1.setVisible(true);
		f1.getContentPane().setBackground(Color.LIGHT_GRAY);
	}
	
	public void actionPerformed(ActionEvent e) {
	
		//
		int mode;
		
		if(e.getSource().equals(b1)){
			f1.dispose();
			mode = 2;		
			mancala_startprepare run= new mancala_startprepare(mode);
		}
		
		if(e.getSource().equals(b2)) {
			f1.dispose();	
			mode = 1;
			mancala_startprepare run= new mancala_startprepare(mode);
		}
		
		if(e.getSource().equals(b3)){
			f1.dispose();
			mancala_welcomegui gui= new mancala_welcomegui();	
		}
	}
}
