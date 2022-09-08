import javax.microedition.midlet.*;
import javax.microedition.lcdui.*;
import javax.microedition.lcdui.game.*;
import java.util.*;

class Constant {
	public static final int DOWN=0;
	public static final int LEFT=1;
	public static final int RIGHT=2;

	public static final int BLK_SIZE=12;
	public static final int SPACE=2;
	public static final int BG_COLOR=0;
	public static final int BORDER_COLOR=16777215;
	public static final int BLK_COLOR_0=16737792;
	public static final int BLK_COLOR_1=16776960;
	public static final int BLK_COLOR_2=3407871;
	public static final int BLK_COLOR_3=65280;
	public static final int TITLE_COLOR=6724095;
	public static final int MARK_COLOR=16711680;

	public static final int MIN_MARGIN=2;

}

class Board {
	private Block [][] b=null;
	private int width,height;

	//A list to hold the block to check whether it should be
	//removed (remove it if 4 or more same color block lie together.
	private Vector checkList=null;

	//A list to hold the block which is deleted in the game board
	//becasue 4 or more same color lie together.
	private Vector deleteList=null;
	private Vector tempDeleteList=null;

	//if vSpace or hSpace =0, use background color,
	//if vSpace or hSpace =-1, no need to repaint,
	//if vSpace or hSpace =1, use b[i][j].color
	private int[][] vSpace=null;
	private int[][] hSpace=null;


/*

For example:

width = 3;
height = 4;

-------->x
| ###
| ###
| ###
| ###
v
y

hSpace is 2*4 (note the "|" mark):

#|#|#
#|#|#
#|#|#
#|#|#

vSpace is 3*3 (note the "-" mark):

###
---
###
---
###
---
###

*/

	Board(int w, int h, Block[][] _b) {
		width=w;
		height=h;
		b=_b;
		hSpace=new int[w-1][h];
		vSpace=new int[w][h-1];

		/*
		Task 1. Initialize every array entries in hSpace and vSpace to be 0.

		.....
		*/
	}

	public void setNotCheck() {
		for(int i=0; i<width; i++) {
			for(int j=height-1; j>=0; j--) {
				if(b[i][j].active) {
					b[i][j].isChecked=false;
				}else{
					break;
				}
			}
		}
	}

	public void addToCheck(int x,int y) {
		if(getBlock(x,y)==null) return;

		if(checkList==null) {
			checkList=new Vector();
		}

		checkList.addElement(b[x][y]);
	}

	//sorted by the y index value
	private void insertList(Vector list,Block t) {
		if(list==null) return;
		int i=0;
		for(; i<list.size(); i++) {
			Block temp=(Block)list.elementAt(i);
			if(temp.indexY<t.indexY) {
				break;
			}
		}

		deleteList.insertElementAt(t,i);
	}

	// Put a numbers of same color in the tempDeletelist
	// starting in position (x,y)
	public void numOfSameColor(int x,int y) {

		if(b[x][y].isChecked) {
			return;
		}
		b[x][y].isChecked=true;

		Block temp=null;

		// Check whether the left block have the same color as the block in (x, y)
		if((temp=getBlock(x+1,y))!=null&&temp.active) {
			if(!temp.isChecked&&b[x][y].color==temp.color) {
				tempDeleteList.addElement(temp);
				setSpace(x,y,1,false);
				numOfSameColor(x+1,y);
			}
		}

		/*
		Task 2: Check whether the right block have the same color as the block in (x, y)
		simlar to 3 other cases:

		if (........) {
			..........
		}
		*/

		// Check whether the top block have the same color as the block in (x, y)
		if((temp=getBlock(x,y-1))!=null&&temp.active) {
			if(!temp.isChecked&&b[x][y].color==temp.color) {
				tempDeleteList.addElement(temp);
				setSpace(x,y-1,1,true);
				numOfSameColor(x,y-1);
			}
		}

		// Check whether the bottom block have the same color as the block in (x, y)
		if((temp=getBlock(x-1,y))!=null&&temp.active) {
			if(!temp.isChecked&&b[x][y].color==temp.color) {
				tempDeleteList.addElement(temp);
				setSpace(x-1,y,1,false);
				numOfSameColor(x-1,y);
			}
		}
	}

	public boolean moveAllDown() {
		Block tempBlk=null;

		if(checkList==null) {
			checkList=new Vector();
		}

		while(deleteList!=null&&deleteList.size()>0) {
			tempBlk=(Block)deleteList.firstElement();
			int numOfSpace=0;
			for(int i=tempBlk.indexY; i>=0; i--) {
				if(!b[tempBlk.indexX][i].active) {
					if(deleteList.removeElement(b[tempBlk.indexX][i])) {
						setFourSpace(tempBlk.indexX,i,0);
					}
					numOfSpace++;
				} else {
					break;
				}
			}

			if(numOfSpace<tempBlk.indexY) {
				for(int j=tempBlk.indexY-numOfSpace; j>=0; j--)	{
					if(b[tempBlk.indexX][j].active) {
						updateBoard(tempBlk.indexX,j,tempBlk.indexX,j+numOfSpace);
						setFourSpace(tempBlk.indexX,j,0);
						checkList.addElement(b[tempBlk.indexX][j+numOfSpace]);
					} else {
						deleteList.removeElement(b[tempBlk.indexX][j]);
						numOfSpace++;
					}
				}
			}
		}

		deleteList=null;
		if(checkList.size()>0) {
			return true;
		}

		checkList=null;
		return false;
	}

	// Check the number of block to be removed.
	public int checkWin() {
		if(checkList==null) {
			return 0;
		}

		if(checkList.size()==0) {
			checkList=null;
			return 0;
		}

		setNotCheck();
		if(deleteList==null) {
			deleteList=new Vector();
		}

		Block tempBlk=null;

		tempBlk=(Block)checkList.firstElement();
		checkList.removeElementAt(0);
		tempDeleteList=new Vector();
		tempDeleteList.addElement(tempBlk);
		numOfSameColor(tempBlk.indexX,tempBlk.indexY);
		int numOfBlk=tempDeleteList.size();

		if(numOfBlk>=4) {
			for(int i=0; i<tempDeleteList.size(); i++) {
				tempBlk=(Block)tempDeleteList.elementAt(i);
				tempBlk.color=Constant.BG_COLOR;
				tempBlk.setUpdate(false);
				tempBlk.active=false;
				insertList(deleteList,tempBlk);
			}
			tempDeleteList=null;
		} else {
			tempDeleteList=null;
			return checkWin();
		}

		return numOfBlk+checkWin();
	}

	// A sychronized function cannot be executed by more than one thread before returned.
	synchronized public boolean updateBoard(int oldx, int oldy, int newx, int newy) {
		if(oldx>width-1||oldx<0||oldy>height-1||oldy<0) {
			return false;
		}

		if(newx>width-1||newx<0||newy>height-1||newy<0) {
			return false;
		}

		if(newx==oldx&&newy==oldy) {
			return true;
		}

		if(b[newx][newy].active) {
			return false;
		}

		// The varibles specified by the sychronized block cannot be executed
		// by more than one thread before returned.
		synchronized(b[newx][newy]) {
			b[newx][newy].active=true;
			b[newx][newy].color=b[oldx][oldy].color;
			b[newx][newy].setUpdate(false);
			b[oldx][oldy].active=false;
			b[oldx][oldy].color=Constant.BG_COLOR;
			b[oldx][oldy].setUpdate(false);
		}
		return true;
	}

	public Block getBlock(int i, int j) {
		try{
			return b[i][j];
		}catch (Exception e) {
			return null;
		}
	}

	public void setFourSpace(int x, int y, int val) {
		setSpace(x-1,y,val,false);
		setSpace(x,y-1,val,true);
		setSpace(x,y,val,true);
		setSpace(x,y,val,false);
	}

	public void setSpace(int x, int y, int val, boolean isVSpace) {
		if(isVSpace) {
			if(x>=0&&y>=0&&x<vSpace.length&&y<vSpace[0].length)	{
				vSpace[x][y]=val;
			}
		} else {
			if(x>=0&&y>=0&&x<hSpace.length&&y<hSpace[0].length)	{
				hSpace[x][y]=val;
			}
		}
	}

	public void drawBoard(Graphics g, boolean unconditioned) { //if unconditioned==true, then print all the blocks no matter update or not
		synchronized(b) {
			for(int i=0; i<width; i++) {
				for(int j=0; j<height; j++) {
					if(!b[i][j].getUpdate()||unconditioned) {
						b[i][j].drawBlock(g);
					}


					int color=0;
					if(i<hSpace.length) {
						if(hSpace[i][j]>=0) {
							// 1. if hSpace[i][j]==0, color=Constant.BG_COLOR;
							// otherwise color=b[i][j].color
							color=(hSpace[i][j]==0)?Constant.BG_COLOR:b[i][j].color;
							// 2. Set the color of Graphics g as the variable "color".
							g.setColor(color);
							// 3. Draw a rectangle in with the left corner=(b[i][j].posX+Constant.BLK_SIZE, b[i][j].posY),
							// width=Constant.SPACE and height=Constant.BLK_SIZE
							g.fillRect(b[i][j].posX+Constant.BLK_SIZE, b[i][j].posY,Constant.SPACE,Constant.BLK_SIZE);
							hSpace[i][j]=-1;
						}
					}

					if(j<vSpace[0].length) {
						if(vSpace[i][j]>=0) {
							/*
							Task 3: Implement the 3 steps to handle "vSpace" similar to the
							codes for hSpace.


							// 1. if vSpace[i][j]==0, color=Constant.BG_COLOR;
							// otherwise color=b[i][j].color

							// 2. Set the color of Graphics g as the variable "color".

							// 3. Draw a rectangle in with the left corner=(b[i][j].posX, b[i][j].posY+Constant.BLK_SIZE),
							// width=Constant.BLK_SIZE and height=Constant.SPACE

							*/
						}
					}
				}
			}
		}
	}
}


class Block {
	public int posX,posY;
	// posX, posY store the position values in terms of pixel
	public int indexX,indexY;
	// posX, posY store the coodinate values in terms of data grid
	public int color;
	public boolean active;
	public boolean isChecked;
	private boolean update;


	public Block(Block b) {
		posX=b.posX;
		posY=b.posY;
		indexX=b.indexX;
		indexY=b.indexY;
		color=b.color;
		active=b.active;
		update=false;
	}

	synchronized public void setUpdate(boolean val) {
		update=val;
	}

	public boolean getUpdate() {
		return update;
	}

	public Block(int _posX, int _posY, int _indexX, int _indexY) {
		posX=_posX;
		posY=_posY;
		indexX=_indexX;
		indexY=_indexY;
		color=Constant.BG_COLOR;
		active=false;
		update=false;
	}

	public void drawBlock(Graphics g) {
		g.setColor(color);
		g.fillRect(posX,posY,Constant.BLK_SIZE,Constant.BLK_SIZE);
		setUpdate(true);
	}

	public static boolean move(Board board, int dir, Block b) {
		switch(dir) {
			case Constant.DOWN: return board.updateBoard(b.indexX,b.indexY,b.indexX,b.indexY+1);
			case Constant.LEFT: return board.updateBoard(b.indexX,b.indexY,b.indexX-1,b.indexY);
			case Constant.RIGHT: return board.updateBoard(b.indexX,b.indexY,b.indexX+1,b.indexY);
		}
		return false;
	}
}

class NextBlock {
	private Block [] blk=null;
	private Random rand;

	NextBlock(int x, int y) {
		rand=new Random();
		blk=new Block[2];
		for(int i=0; i<2; i++) {
			blk[i]=new Block(x,y+i*(Constant.SPACE+Constant.BLK_SIZE),-1,-1);
			blk[i].active=true;
			blk[i].setUpdate(true);
		}
	}

	public void genNextBlock(){
		int tempColor=-1;
		for(int i=0; i<2; i++) {
			switch((Math.abs(rand.nextInt()))%4){
				case 0:	tempColor=Constant.BLK_COLOR_0;	break;
				case 1:	tempColor=Constant.BLK_COLOR_1;	break;
				case 2:	tempColor=Constant.BLK_COLOR_2;	break;
				case 3:	tempColor=Constant.BLK_COLOR_3;	break;
			}
			blk[i].color=tempColor;
			blk[i].setUpdate(false);
		}
	}

	public void drawNextBlock(Graphics g, boolean unconditioned) { //if unconditioned==true, then print all the blocks no matter update or not
		for(int i=0; i<2; i++) {
			if(!blk[i].getUpdate()||unconditioned) {
				blk[i].drawBlock(g);
			}
		}
	}

	public int[] getNextBlockColor(){
		int [] tempColor=new int[2];
		tempColor[0]=blk[0].color;
		tempColor[1]=blk[1].color;
		return tempColor;
	}
}

class ActiveBlock {
	private Board board=null;
	private Block [] blk=null;
	PuzzleCanvas puzzle=null;
	/*
	 * 0:	x
	 *		o
	 *
	 * 1:	xo
	 *
	 * 2:	o
	 *		x
	 *
	 * 3:	ox
	 */
	int type;

	ActiveBlock(Board b, int color[],PuzzleCanvas p) {
		board=b;
		puzzle=p;
		blk=new Block[2];
		for(int i=0; i<2; i++) {

			blk[i]=board.getBlock(3,i);
			if(blk[i].active) {
				puzzle.lost=true;
			}
			blk[i].active=true;
			blk[i].color=color[i];
			blk[i].setUpdate(false);
		}
		type=0;
	}

	public void changeType() {
		int oldx=blk[0].indexX;
		int oldy=blk[0].indexY;
		int newx=-1;
		int newy=-1;
		boolean isOK=false;
		switch(type) {
			case 0:	isOK=board.updateBoard(oldx, oldy, oldx-1,oldy+1);
					newx=oldx-1;
					newy=oldy+1;
					break;
			case 1:	isOK=board.updateBoard(oldx, oldy, oldx+1,oldy+1);
					newx=oldx+1;
					newy=oldy+1;
					break;
			case 2:	isOK=board.updateBoard(oldx, oldy, oldx+1,oldy-1);
					/*
					Task 4: To rotate anti-clock wise, update the coordinate of blk[0],
					        implement the 4 line below:
					*/
					// 1. Update newx
					// 2. Update newy
					break;
			case 3:	isOK=board.updateBoard(oldx, oldy, oldx-1,oldy-1);
					// 3. Update newx
					// 4. Update newy
					break;
		}
		if(isOK) {
			type=(type+1)%4;
			blk[0]=board.getBlock(newx,newy);
		}

	}

	synchronized public int move(int dir) {

		int numOfUpdate=0; // Numbers of block touches groud.

		if(dir==Constant.DOWN) {
			if(type==0||type==2) {
				int i=(type==0)?0:1;
				if(board.updateBoard(blk[1-i].indexX,blk[1-i].indexY,blk[1-i].indexX,blk[1-i].indexY+1)) {
					blk[1-i]=board.getBlock(blk[1-i].indexX,blk[1-i].indexY+1);
					board.updateBoard(blk[i].indexX,blk[i].indexY,blk[i].indexX,blk[i].indexY+1);
					blk[i]=board.getBlock(blk[i].indexX,blk[i].indexY+1);
					numOfUpdate=2;
				}
			} else {
				for(int i=0; i<2; i++) {
					if(board.updateBoard(blk[i].indexX,blk[i].indexY,blk[i].indexX,blk[i].indexY+1)) {
						blk[i]=board.getBlock(blk[i].indexX,blk[i].indexY+1);
						numOfUpdate++;
					}
				}
			}
		}


		if(dir==Constant.LEFT) {
			if(type==1||type==3) {
				int i=(type==1)?1:0;
				if(board.updateBoard(blk[1-i].indexX,blk[1-i].indexY,blk[1-i].indexX-1,blk[1-i].indexY)) {
					blk[1-i]=board.getBlock(blk[1-i].indexX-1,blk[1-i].indexY);
					board.updateBoard(blk[i].indexX,blk[i].indexY,blk[i].indexX-1,blk[i].indexY);
					blk[i]=board.getBlock(blk[i].indexX-1,blk[i].indexY);
					numOfUpdate=2;
				}
			} else {
				int i=(type==0)?0:1;
				if(board.updateBoard(blk[1-i].indexX,blk[1-i].indexY,blk[1-i].indexX-1,blk[1-i].indexY)) {
					blk[1-i]=board.getBlock(blk[1-i].indexX-1,blk[1-i].indexY);

					board.updateBoard(blk[i].indexX,blk[i].indexY,blk[i].indexX-1,blk[i].indexY);
					blk[i]=board.getBlock(blk[i].indexX-1,blk[i].indexY);
					numOfUpdate=2;
				}
			}
		}


		if(dir==Constant.RIGHT) {
			if(type==1||type==3) {
				int i=(type==1)?0:1;
				if(board.updateBoard(blk[1-i].indexX,blk[1-i].indexY,blk[1-i].indexX+1,blk[1-i].indexY)) {
					blk[1-i]=board.getBlock(blk[1-i].indexX+1,blk[1-i].indexY);
					board.updateBoard(blk[i].indexX,blk[i].indexY,blk[i].indexX+1,blk[i].indexY);
					blk[i]=board.getBlock(blk[i].indexX+1,blk[i].indexY);
					numOfUpdate=2;
				}
			} else {
				int i=(type==0)?0:1;
				if(board.updateBoard(blk[1-i].indexX,blk[1-i].indexY,blk[1-i].indexX+1,blk[1-i].indexY)) {
					blk[1-i]=board.getBlock(blk[1-i].indexX+1,blk[1-i].indexY);
					board.updateBoard(blk[i].indexX,blk[i].indexY,blk[i].indexX+1,blk[i].indexY);
					blk[i]=board.getBlock(blk[i].indexX+1,blk[i].indexY);
					numOfUpdate=2;
				}
			}
		}
		return numOfUpdate;
	}

	public Block[] getBlock() {
		return blk;
	}

}


class PuzzleCanvas extends GameCanvas implements Runnable {
	private Board board=null;
	private int bWidth=(getWidth()*25)/35; //maximum width for game board
	private int bHeight=getHeight(); //maximum height for game board
	private int hMargin=-1;
	private int vMargin=-1;
	private boolean paintBorder;
	private boolean start;
	private boolean exit;
	private NextBlock nextBlk;
	private ActiveBlock activeBlk;
	private boolean waitForActiveBlk;
	public int speed;
	private int marks;
	public boolean lost;
	private boolean updatedMark;

	PuzzleCanvas() {
		super(false);
		start=false;
		exit=false;
		lost=false;
		paintBorder=true;
		waitForActiveBlk=false;

		initBoard();
	}

	public void incSpeed() {
		if(speed<1000) {
			speed+=50;
		}
	}

	public void decSpeed() {
		if(speed>100) {
			speed-=50;
		}
	}

	public void startGame() {
		waitForActiveBlk=false;
		paintBorder=true;
		speed=500;
		marks=0;
		updatedMark=true;
		initBoard();

		nextBlk.genNextBlock();
		activeBlk=new ActiveBlock(board,nextBlk.getNextBlockColor(),this);

		nextBlk.genNextBlock();
		lost=false;
		start=true;
		repaint();
	}

	public void exitGame() {
		exit=true;
	}

	public void initBoard() {
		int numOfVBlock=0;
		int numOfHBlock=0;
		int hTemp=bWidth-Constant.SPACE-Constant.MIN_MARGIN;
		int vTemp=bHeight-Constant.SPACE-Constant.MIN_MARGIN;

		for(;;) {
			if(hTemp<Constant.BLK_SIZE+Constant.SPACE) {
				break;
			}else {
				hTemp-=Constant.BLK_SIZE+Constant.SPACE;
				numOfHBlock++;
			}
		}

		hMargin=(hTemp+Constant.MIN_MARGIN)/2;


		for(;;) {
			if(vTemp<Constant.BLK_SIZE+Constant.SPACE) {
				break;
			}else {
				vTemp-=Constant.BLK_SIZE+Constant.SPACE;
				numOfVBlock++;
			}
		}

		vMargin=(vTemp+Constant.MIN_MARGIN)/2;

		Block [][] tempBlk=new Block[numOfHBlock][numOfVBlock];
		for(int i=0; i<numOfHBlock; i++) {
			for(int j=0; j<numOfVBlock; j++) {
				tempBlk[i][j]=new Block(hMargin+Constant.SPACE+i*(Constant.BLK_SIZE+Constant.SPACE),
										vMargin+Constant.SPACE+j*(Constant.BLK_SIZE+Constant.SPACE),
										i,
										j);

			}
		}

		board=new Board(numOfHBlock,numOfVBlock,tempBlk);
		int temp=(getWidth()-bWidth-hMargin)/2-Constant.BLK_SIZE/2;
		nextBlk=new NextBlock(bWidth+temp,vMargin+temp-Constant.SPACE/2-Constant.BLK_SIZE/2);

	}

	public void drawBGBorder(Graphics g) {
		if(!paintBorder){
			return;
		}
		/*game border*/
		g.setColor(Constant.BG_COLOR);
		g.fillRect(0,0,getWidth(),getHeight());

		g.setColor(Constant.BORDER_COLOR);
		g.drawRect(hMargin,vMargin,bWidth-2*hMargin,bHeight-2*vMargin);

		/*next block Broder*/
		int len=getWidth()-bWidth-hMargin;
		g.drawRect(bWidth,vMargin,len,len);

		/*Mark broder*/
		g.drawRect(bWidth,vMargin+len+vMargin,len,getHeight()-len-3*vMargin);

		g.setColor(Constant.TITLE_COLOR);
		g.drawString("Marks:",bWidth+25,vMargin+len+vMargin+30,Graphics.HCENTER|Graphics.BASELINE);
		paintBorder=false;
	}



	public void drawMark(Graphics g) {
		if(!updatedMark) {
			return;
		}

		int len=getWidth()-bWidth-hMargin;
		/*Mark broder*/
		g.setColor(Constant.BG_COLOR);
		g.fillRect(bWidth,vMargin+len+vMargin,len,getHeight()-len-3*vMargin);

		g.setColor(Constant.BORDER_COLOR);
		g.drawRect(bWidth,vMargin+len+vMargin,len,getHeight()-len-3*vMargin);

		g.setColor(Constant.TITLE_COLOR);
		g.drawString("Marks:",bWidth+25,vMargin+len+vMargin+30,Graphics.HCENTER|Graphics.BASELINE);

		g.setColor(Constant.MARK_COLOR);
		g.drawString(marks+"",bWidth+22,vMargin+len+vMargin+48,Graphics.HCENTER|Graphics.BASELINE);
		if(lost) {
			g.setColor(Constant.TITLE_COLOR);
			g.drawString("[Game",bWidth+25,vMargin+len+vMargin+70,Graphics.HCENTER|Graphics.BASELINE);
			g.drawString("Over]",bWidth+25,vMargin+len+vMargin+88,Graphics.HCENTER|Graphics.BASELINE);
		}

	}

	synchronized public void paint(Graphics g) {
		drawBGBorder(g);
		board.drawBoard(g,false);
		nextBlk.drawNextBlock(g,false);
		drawMark(g);
	}


	public void keyRepeated(int keyCode) {
		keyPressed(keyCode);
	}

	synchronized public boolean changeWaitForActiveBlk(boolean isGet, boolean val) {
		if(isGet) {
			return waitForActiveBlk;
		}
		waitForActiveBlk=val;
		return waitForActiveBlk;
	}

	public void keyPressed(int keyCode) {
		if(!start||lost) {
			return;
		}
		if(changeWaitForActiveBlk(true,true)) {
			return;
		}


		boolean called=true;
		synchronized(activeBlk) {
			switch(keyCode) {
				// case KEY_NUM1:	incSpeed(); break;
				// case KEY_NUM3:	decSpeed(); break;
				case KEY_NUM5:	activeBlk.changeType(); break;
				case KEY_NUM8:	activeBlk.move(Constant.DOWN); break;
				case KEY_NUM6:	activeBlk.move(Constant.RIGHT); break;
				case KEY_NUM4:	activeBlk.move(Constant.LEFT); break;
				default: called=false;
			}
			if(!called) {
				switch(getGameAction(keyCode)) {
					case Canvas.FIRE:	activeBlk.changeType(); break;
					case Canvas.DOWN:	activeBlk.move(Constant.DOWN); break;
					case Canvas.RIGHT:	activeBlk.move(Constant.RIGHT); break;
					case Canvas.LEFT:	activeBlk.move(Constant.LEFT); break;
				}
			}
			repaint();
		}
	}

	public void run(){
		while(true) {
			while(!start&&!exit) {
				try{
					Thread.sleep(200);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}

			while(!exit&&!lost) {
				try{
					Thread.sleep(speed);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
				int ret=activeBlk.move(Constant.DOWN);
				synchronized(activeBlk) {
					changeWaitForActiveBlk(false,true);

					if(ret==0) {

						Block [] tempBlk=activeBlk.getBlock();

						board.addToCheck(tempBlk[0].indexX,tempBlk[0].indexY);
						board.addToCheck(tempBlk[1].indexX,tempBlk[1].indexY);
						int i=0;
						do{
							i++;
							marks+=i*board.checkWin();
							updatedMark=true;

							/* Task 5: Call moveAllDown() by the object board.
										if it return false, break the loop.
							*/

							repaint();
							try{
								Thread.sleep(speed/2);
							} catch (InterruptedException e) {
								e.printStackTrace();
							}
						}while(true);
						tempBlk=null;

						activeBlk=new ActiveBlock(board,nextBlk.getNextBlockColor(),this);

						nextBlk.genNextBlock();

						changeWaitForActiveBlk(false,false);
					}

					if(ret==2) {
						changeWaitForActiveBlk(false,false);
					}
				}
				repaint();
			}
			if(exit) {
				break;
			}
		}
	}
}


public class PuzzleMIDlet extends MIDlet implements CommandListener {
	private Command exit=new Command("Exit",Command.EXIT,1);
	private Command start=new Command("Start",Command.BACK,1);
	private PuzzleCanvas puzzle;

	public PuzzleMIDlet() {

		puzzle=new PuzzleCanvas();

		/* Task 6:
			1. Add command exit to PuzzleCanvas "puzzle".
			2. Add command start to PuzzleCanvas "puzzle".
			3. Set the command listener of PuzzleCanvas to PuzzleMIDlet class ("this" class).
		*/

	}

	public void commandAction(Command cmd,Displayable display) {
		if(cmd==exit) {
			puzzle.exitGame();
			destroyApp(false);
			notifyDestroyed();
		} else if(cmd==start) {
			puzzle.startGame();
		}


	}

	public void startApp() {
		Display.getDisplay(this).setCurrent(puzzle);
		Thread thread=new Thread(puzzle);
		thread.run();
	}

	public void pauseApp() {

	}

	public void destroyApp(boolean unconditional) {

	}

}


