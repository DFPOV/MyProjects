import java.util.Random;
import java.util.Scanner;

public class mancala_rules {
	
	static Scanner input = new Scanner(System.in);
		// extra round rule
		public boolean extrarule1(int player, int land) {
			if (player == 1 && land == 6) {
				return true;
			}
				
			if (player == 2 && land == 13) {
				return true;
			}
				
			// default return
			else {
				return false;
			}
		}
			
		// stone robber rule
		public boolean extrarule2(int player, int land,int[] line) {
			if (line[land] == 1 && player == 1 && land < 6 && line[12 - land] != 0) {
				line[6] = line[6] + 1 + line[12 - land];
				line[12 - land] = 0;
				line[land] = 0;
				return true;
			}
			
			if (line[land] == 1 && player == 2 && land < 13 && land > 6 && line[12 - land] != 0) {
				line[13] = line[13] + 1 + line[12 - land];
				line[12 - land] = 0;
				line[land] = 0;
				return false;
			}
			else {
				return false;
			}
		}
		
		public boolean emptymove(int[] line, int index) {			
			if(line[index] == 0) {
				return false;
			}
			return true;
		}
			
		public int setzero(int[] line, int index) {
			int land = 0;
			
			if(index + line[index] > 13) {					
				for(int i = index; i < 14; i++) {
					line[i] += 1; 
				}
					
				int x = index + line[index] - 14;
				for (int i = 0; i < x; i++) {
					line[i] += 1;
					land = i;
				}
			}
		
			// check if it's out of range
			else{
				for(int i = index; i < index+line[index]; i++) {
					line[i] += 1; 
					land = i;
				}
			}				
			line[index] = 0;
			
			return land;
		}
}