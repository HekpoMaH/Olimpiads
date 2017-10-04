import java.io.*;
import java.util.Arrays;

public class EllysCards
{
	String suits = "SDHC";
	String ranks = "23456789TJQKA";
	
	int MM = 52;
	int[] hand, pile, dyn;
	int[] suitPoints, cntSuit;
	int[] rankPoints, cntRank;

	void encode()
	{
		int tmp, suit = 0;
		int idx1 = -1, idx2 = -1;
		while (cntSuit[suit] < 2) suit++;
		for (int i = 0; i < 5; i++) if ((hand[i] & 3) == suit)
		{
			if (idx1 == -1 || hand[i] < hand[idx1])
				{idx2 = idx1; idx1 = i;}
			else if (idx2 == -1 || hand[i] < hand[idx2])
				idx2 = i;
		}

		int dist = (hand[idx2] - hand[idx1]) >> 2;
		if (dist > 6) {tmp = idx1; idx1 = idx2; idx2 = tmp; dist = 13 - dist;}
		tmp = hand[idx2]; hand[idx2] = hand[4]; hand[4] = tmp;
		if (idx1 == 4) idx1 = idx2;
		tmp = hand[idx1]; hand[idx1] = hand[0]; hand[0] = tmp;

		if (hand[2] < hand[1]) {tmp = hand[1]; hand[1] = hand[2]; hand[2] = tmp;}
		if (hand[3] < hand[2]) {tmp = hand[2]; hand[2] = hand[3]; hand[3] = tmp;}
		if (hand[2] < hand[1]) {tmp = hand[1]; hand[1] = hand[2]; hand[2] = tmp;}
		
		tmp = hand[1]; hand[1] = hand[(dist + 1) >> 1]; hand[(dist + 1) >> 1] = tmp;
		if ((hand[2] < hand[3]) ^ ((dist & 1) > 0)) {tmp = hand[2]; hand[2] = hand[3]; hand[3] = tmp;}
	}
	
	int recurse(int idx)
	{
		if (idx >= pile.length) return 0;
		int dynIdx = hand[3] + MM * (hand[2] + MM * (hand[1] + MM * hand[0]));
		if (dyn[dynIdx] != -1) return dyn[dynIdx];

		int ans = 0;
		int[] save = new int[5];
		for (int i = 0; i < 5; i++) save[i] = hand[i];

		for (int i = 0; i < 5; i++)
		{
			cntSuit[hand[i] & 3]--; cntRank[hand[i] >> 2]--;
			cntSuit[pile[idx] & 3]++; cntRank[pile[idx] >> 2]++;			

			hand[i] = pile[idx];
			encode();
			int maxSuit = cntSuit[0];
			for (int c = 1; c < 4; c++)
				maxSuit = Math.max(maxSuit, cntSuit[c]);
			int maxRank = cntRank[hand[0] >> 2];
			for (int c = 1; c < 5; c++)
				maxRank = Math.max(maxRank, cntRank[hand[c] >> 2]);
			ans = Math.max(ans, suitPoints[maxSuit] + rankPoints[maxRank] + recurse(idx + 1));
			
			for (int c = 0; c < 5; c++) hand[c] = save[c];
			cntSuit[hand[i] & 3]++; cntRank[hand[i] >> 2]++;
			cntSuit[pile[idx] & 3]--; cntRank[pile[idx] >> 2]--;
		}
		return dyn[dynIdx] = ans;
	}	
	public int getCard(String card)
	{
		int ret = 0;
		for (int i = 0; i < 13; i++)
			if (card.charAt(0) == ranks.charAt(i)) ret |= (i << 2);
		for (int i = 0; i < 4; i++)
			if (card.charAt(1) == suits.charAt(i)) ret |= i;
		return ret;
	}

	public int getMaximum(String[] hand_, String[] pile_, int[] suitPoints_, int[] rankPoints_)
	{
		hand = new int[hand_.length];
		pile = new int[pile_.length];
		dyn = new int[MM * MM * MM * MM];
		suitPoints = suitPoints_; cntSuit = new int[4];
		rankPoints = rankPoints_; cntRank = new int[13]; 
		
		for (int i = 0; i < hand.length; i++)
		{
			hand[i] = getCard(hand_[i]);
			cntSuit[hand[i] & 3]++; cntRank[hand[i] >> 2]++;
		}
		for (int i = 0; i < pile.length; i++)
			pile[i] = getCard(pile_[i]);
		
		encode();
		Arrays.fill(dyn, -1);
		int ans = recurse(0);
		
		int cnt = 0;
		for (int i = 0; i < MM; i++)
			for (int c = 0; c < MM; c++)
				for (int j = 0; j < MM; j++)
					for (int k = 0; k < MM; k++)
						if (dyn[k + MM * (j + MM * (c + MM * i))] != -1) cnt++;
		System.out.println("Total number of occupied cells is " + cnt);
		return ans;
	}
	
	public boolean isValidCard(String card)
	{
		boolean suitOkay = false;
		for (int i = 0; i < suits.length(); i++)
			if (suits.charAt(i) == card.charAt(1)) suitOkay = true;
		boolean rankOkay = false;
		for (int i = 0; i < ranks.length(); i++)
			if (ranks.charAt(i) == card.charAt(0)) rankOkay = true;
		return suitOkay && rankOkay;
	}
	
	public String checkData(String[] hand, String[] pile, int[] suitPoints, int[] rankPoints)
	{
		int PILE_MIN_SIZE = 1;
		int PILE_MAX_SIZE = 47;
		int HAND_SIZE = 5;
		int SUIT_POINTS_SIZE = 6;
		int RANK_POINTS_SIZE = 5;
		
		if (hand.length != HAND_SIZE)
			return "String[] hand should contain exactly " + HAND_SIZE + " elements.";
		if (suitPoints.length != SUIT_POINTS_SIZE)
			return "int[] suitPoints should contain exactly " + SUIT_POINTS_SIZE + " elements.";
		if (rankPoints.length != RANK_POINTS_SIZE)
			return "int[] rankPoints should contain exactly " + RANK_POINTS_SIZE + " elements.";
		if (pile.length < PILE_MIN_SIZE || pile.length > PILE_MAX_SIZE)
			return "String[] pile should contain between " + PILE_MIN_SIZE + " and " +
					PILE_MAX_SIZE + " elements, inclusive.";
		
		for (int i = 0; i < hand.length; i++)
			if (!isValidCard(hand[i])) return "String[] hand contains invalid card \"" + hand[i] + "\".";
		for (int i = 0; i < pile.length; i++)
			if (!isValidCard(pile[i])) return "String[] pile contains invalid card \"" + pile[i] + "\".";
		
		if (suitPoints[0] != 0)
			return "The first element of suitPoints should be 0.";
		if (rankPoints[0] != 0)
			return "The first element of rankPoints should be 0.";
		
		String[] cards = new String[hand.length + pile.length];
		for (int i = 0; i < hand.length; i++)
			cards[i] = hand[i];
		for (int i = 0; i < pile.length; i++)
			cards[hand.length + i] = pile[i];
		
		for (int i = 0; i < cards.length; i++)
			for (int c = i + 1; c < cards.length; c++)
				if (cards[i].compareTo(cards[c]) == 0)
					return "All cards must be distinct.";
		
		return "";
	}
	

	public static String[] parseVectorString(String line)
	{
		String[] arr = line.split(" ");
		for (int i = 0; i < arr.length; i++)
		{
			arr[i] = arr[i].replaceAll("[{,}]", " ");
			arr[i] = arr[i].trim();
			arr[i] = arr[i].substring(1, arr[i].length() - 1);
		}
		return arr;
	}

	public static int[] parseVectorInt(String line)
	{
		String[] arr = line.split(" ");
		for (int i = 0; i < arr.length; i++)
		{
			arr[i] = arr[i].replaceAll("[{,}]", " ");
			arr[i] = arr[i].trim();
		}
		int[] ret = new int[arr.length];
		for (int i = 0; i < arr.length; i++)
			ret[i] = Integer.parseInt(arr[i]);
		return ret;
	}

	public static void main(String[] args) throws FileNotFoundException, IOException
	{
		File inpFile = new File("D:\\espr1t\\myTasks\\Unfinished\\EllysCards\\EllysCards.in");
		BufferedReader in = new BufferedReader(new FileReader(inpFile));
		
		String line = in.readLine();
		int numTests = Integer.parseInt(line);
		
		for (int curTest = 0; curTest < numTests; curTest++)
		{
			line = in.readLine();
			String[] hand = parseVectorString(line);
			line = in.readLine();
			String[] deck = parseVectorString(line);
			line = in.readLine();
			int[] suitPoints = parseVectorInt(line);
			line = in.readLine();
			int[] rankPoints = parseVectorInt(line);
			
			long sTime = System.currentTimeMillis();
			EllysCards ellysCards = new EllysCards();
			if (ellysCards.checkData(hand, deck, suitPoints, rankPoints) != "")
				System.out.println(ellysCards.checkData(hand, deck, suitPoints, rankPoints));
			System.out.println(ellysCards.getMaximum(hand, deck, suitPoints, rankPoints));
			long eTime = System.currentTimeMillis();
			System.out.println("Execution time: " + ((eTime - sTime) / 1000.0) + " on test " + curTest);
		}
	}
}
