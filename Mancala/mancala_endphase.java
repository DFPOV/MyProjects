import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextArea;

public class mancala_endphase extends JFrame {
	
	static JFrame f1 = new JFrame();
	static JTextArea TA1 = new JTextArea("One player's pit is empty" ,10,10);
	
	static JLabel l1 = new JLabel("Game Over!" );
	static JLabel p1 = new JLabel();
	static JLabel p2 = new JLabel();
	static JLabel wal = new JLabel();
	
	static JButton replay = new JButton("restart");
	static int p1score;
	static int p2score;
	
	public mancala_endphase() {

		TA1.setFont(new Font("Serif", Font.ITALIC, 35));
		TA1.setOpaque(false);
	    TA1.setEditable(false);
	    TA1.setWrapStyleWord(false);
	    TA1.setLineWrap(true);
		TA1.setBounds(480,20,1000,100);  
		
		l1.setBounds(550,100,1000,300);   
		l1.setFont(new Font(null,Font.PLAIN,35));
		
		p1.setBounds(500,200,1000,300);   
		p1.setFont(new Font(null,Font.PLAIN,20));
		
		p2.setBounds(500,300,1000,300);   
		p2.setFont(new Font(null,Font.PLAIN,20));
		
		wal.setFont(new Font(null,Font.PLAIN,20));
	
		replay.setBounds(600,500,100,50);
		replay.addActionListener(new replaylistener());
		replay.setFont(new Font(null,Font.PLAIN,20));
		
		f1.add(TA1);
		f1.add(l1);
		f1.add(p1);
		f1.add(p2);
		f1.add(replay);f1.add(wal);
		 
		f1.setSize(1980,1080);
		f1.setLayout(null);
		f1.setVisible(true);
		f1.getContentPane().setBackground(Color.LIGHT_GRAY);
	}
	
	public void pass(int score1, int score2) {
		p1score = score1;
		p2score = score2;
		p1.setText("plyaer 1 :" + p1score);
		p2.setText("plyaer 2 :" + p2score);
		
		if (p1score > p2score) {
			wal.setBounds(650,200,1000,300);
			wal.setText("Player1 win!");
		}
		
		else if (p2score > p1score) {
			wal.setBounds(650,300,1000,300);
			wal.setText("Player2 win!");
		}
		
		else if (p1score == p2score) {
			wal.setBounds(650,250,1000,300);
			wal.setText("It's a draw!");
		}
	}

	class replaylistener implements ActionListener{
		
		public void actionPerformed(ActionEvent e) {
			if (e.getSource().equals(replay)) {
				mancala_welcomegui gui = new mancala_welcomegui();
				f1.dispose();
			}
		}
	}
}