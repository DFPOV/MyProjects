	import java.awt.Color;
	import java.awt.Font;
	import java.awt.event.ActionEvent;
	import java.awt.event.ActionListener;
	import javax.swing.JButton;
	import javax.swing.JFrame;
	import javax.swing.JTextArea;

	public class mancala_welcomegui implements ActionListener{

		static JFrame f1 = new JFrame();
		static JButton b1 = new JButton("Next"); 

	    static JTextArea TA1 = new JTextArea("Welcome" ,10,10);
	    static JTextArea TA2 = new JTextArea("Rules:",10,10);
	    static JTextArea TA3 = new JTextArea("~This game is counter clockwise." ,10,10);
	    static JTextArea TA4 = new JTextArea("~Pits are from 1 to 6." ,10,10);
	    static JTextArea TA5 = new JTextArea("6<5<4<3<2<1" ,10,10);
	    static JTextArea TA6 = new JTextArea("1>2>3>4>5>6 ",10,10);
	    static JTextArea TA7 = new JTextArea("~If the last stone is landed on players home bin,that player gets another round." ,10,10);
	    static JTextArea TA8 = new JTextArea("~If the last stone of a stack was landed on a emty pit of that player's side," ,10,10);
	    static JTextArea TA9 = new JTextArea("  that player gets all the stones on the opposite opponent pit." ,10,10);
	    static JTextArea TA10 = new JTextArea("~The game end when one of the player has no more stone in their pit.",10,10);
	     
		public mancala_welcomegui(){
		
		b1.setBounds(600,550,100,50);  
		b1.addActionListener(this);
		
		TA1.setFont(new Font("Serif", Font.ITALIC, 50));
		TA1.setOpaque(false);
	    TA1.setEditable(false);
	    TA1.setWrapStyleWord(false);
	    TA1.setLineWrap(true);
		TA1.setBounds(550,20,200,100);  
			
		TA2.setFont(new Font("Serif", Font.ITALIC, 25));
		TA2.setOpaque(false);
		TA2.setEditable(false);
		TA2.setWrapStyleWord(false);
		TA2.setLineWrap(true);
		TA2.setBounds(40,70,1000,35);  
		
		TA3.setFont(new Font("Serif", Font.ITALIC, 25));
		TA3.setOpaque(false);
		TA3.setEditable(false);
		TA3.setWrapStyleWord(true);
		TA3.setLineWrap(true);
		TA3.setBounds(40,100,1000,35);  
		
		TA4.setFont(new Font("Serif", Font.ITALIC, 25));
		TA4.setOpaque(false);
		TA4.setEditable(false);
		TA4.setWrapStyleWord(true);
		TA4.setLineWrap(true);
		TA4.setBounds(40,150,1000,35);  
		
		TA5.setFont(new Font("Serif", Font.ITALIC, 25));
		TA5.setOpaque(false);
		TA5.setEditable(false);
		TA5.setWrapStyleWord(true);
		TA5.setLineWrap(true);
		TA5.setBounds(40,200,1000,35);  
		
		TA6.setFont(new Font("Serif", Font.ITALIC, 25));
		TA6.setOpaque(false);
		TA6.setEditable(false);
		TA6.setWrapStyleWord(true);
		TA6.setLineWrap(true);
		TA6.setBounds(40,250,1000,35);  
		
		TA7.setFont(new Font("Serif", Font.ITALIC, 25));
		TA7.setOpaque(false);
		TA7.setEditable(false);
		TA7.setWrapStyleWord(true);
		TA7.setLineWrap(true);
		TA7.setBounds(40,300,1000,35);  
		
		TA8.setFont(new Font("Serif", Font.ITALIC, 25));
		TA8.setOpaque(false);
		TA8.setEditable(false);
		TA8.setWrapStyleWord(true);
		TA8.setLineWrap(true);
		TA8.setBounds(40,350,1000,35);  
		
		TA9.setFont(new Font("Serif", Font.ITALIC, 25));
		TA9.setOpaque(false);
		TA9.setEditable(false);
		TA9.setWrapStyleWord(true);
		TA9.setLineWrap(true);
		TA9.setBounds(40,400,1000,35);  
		
		TA10.setFont(new Font("Serif", Font.ITALIC, 25));
		TA10.setOpaque(false);
		TA10.setEditable(false);
		TA10.setWrapStyleWord(true);
		TA10.setLineWrap(true);
		TA10.setBounds(40,450,1000,35);  
		
		f1.add(b1);
	    f1.add(TA1);
	    f1.add(TA2);
	    f1.add(TA3);
	    f1.add(TA4);
	    f1.add(TA5);
	    f1.add(TA6);
	    f1.add(TA7);
	    f1.add(TA8);
	    f1.add(TA9);
	    f1.add(TA10);
	     
		f1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f1.setSize(1980,1080);
		f1.setLayout(null);
		f1.setVisible(true);
		f1.getContentPane().setBackground(Color.LIGHT_GRAY);
		}

		public void actionPerformed(ActionEvent e) {
			
			if(e.getSource().equals(b1)){
				f1.dispose();
				mancala_choosestones stone= new mancala_choosestones();
			}
		}
	}
