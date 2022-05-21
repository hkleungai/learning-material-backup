import java.io.* ;
import java.net.* ;
import java.util.* ;
import java.text.*;

final class HttpRequest implements Runnable
{
    final static String CRLF = "\r\n";
    Socket socket;
    
    // Constructor
    public HttpRequest(Socket socket) throws Exception 
    {
	this.socket = socket;
    }
    
    // Implement the run() method of the Runnable interface.
    public void run()
    {
	try {
	    processRequest();
	} 
	catch (Exception e) {
	    System.out.println(e);
	}
	
    }
    
    private void processRequest() throws Exception	{
	

	// Get a reference to the socket's input and output streams.
	InputStream is = /*Fill in*/
	DataOutputStream os = /*Fill in*/
	PrintStream ps = /*Fill in*/
	
	// Set up input stream filters.
	InputStreamReader sr = /*Fill in*/
	BufferedReader br = /*Fill in*/
	
	// Get the request line of the HTTP request message.
	String requestLine = br.readLine();
	


	// Display the request line.
	System.out.println();
	System.out.println("<============Client Request Headers===========>");
	System.out.println(requestLine);
	
	// Get and display the header lines, and constuct the forward header lines
	String headerLine = "";
	String hostLine = "";
	String forwardHeader = "";
	Date   ifModified = null;
	while ((headerLine = br.readLine()).length() != 0) {
	    
	    if( headerLine.startsWith("If-Modified-Since: ") ){
		ifModified = /*Fill in*/
	    }
	    // Check if it is not a header which the proxy should not forward to
	    else if ( !headerLine.startsWith("If-None-Match: ") && /*Fill in && ...*/ ) {

		if ( headerLine.startsWith("Host: ")){
		    hostLine = /**/
		}
		forwardHeader = /**/

	    }	
	    System.out.println(headerLine);			
	}
	forwardHeader += "Connection: close" + CRLF;
	forwardHeader = forwardHeader + "Proxy-Connection: close" + CRLF;
	
	// Extract the method and URI from the request line.
	StringTokenizer tokens = new StringTokenizer(/*Fill in*/);
	/*Ask to fill up*/
	String method = /*Fill in*/
	String URI = /*Fill in*/
	
	
	String hostName = "";
	int hostPort=80;
	// Extract the destination Web server's host name and port number
	if( !hostLine.equals("") ){
	    tokens = new StringTokenizer(hostLine," :");
	    hostName = /*Fill in*/
	    if( /*Fill in*/ )
		hostPort = /*Fill in*/
	}
	
	
	
	if ( method.equals("GET") || method.equals("HEAD") ) {	

	

	    //Resolve the Inet Address of the destination Web Server		
	    InetAddress hostAddr = null;		
	    try{
		hostAddr = /*Fill in*/
	    }catch (UnknownHostException e){
		//Unknown Host: send reponse code and exit
		sendResponse(ps,502,"Unknown Host - "+hostName);
		ps.close();
		br.close();
		socket.close();		
		return;
	    }


	    //Connect to the destination Web server
	    Socket webServSocket = null;
	    try{
		webServSocket = /*Fill in*/
	    }catch( SocketException e ){
		//Unknown Host: send reponse code and exit
		sendResponse(ps,502,"Cannot connect to host - "+hostName + ":" + hostPort);
		ps.close();
		br.close();
		socket.close();		
		return;		
	    }

	    /*Ask to construct*/
	    //Connected to destination web server, get the inputStream and outputStraem
	    DataInputStream webIs = /*Fill in*/
	    DataOutputStream webOs = /*Fill in*/
	    PrintStream webPs = /*Fill in*/
	    
	    System.out.println("<<============================================>>");
	    System.out.println("Connected to Web Server - "+hostName+":"+hostPort);

	    //Send the request line
	    webPs.print(/*Fill in*/);
	    //Send the header lines
	    webPs.print(/*Fill in*/);
	    webPs.print(CRLF);

	    System.out.println("<<==========Forward Request Header===========>>");
	    System.out.println(requestLine);
	    System.out.println(forwardHeader);


	    //Construct a 1k byte array for buffering the response message (HTTP Header + entry)
	    byte[] buffer = new byte[1024];
	    int recvBytes = 0;


	    //Waiting for response
	    if( (recvBytes=/*Fill in*/)>0 ){

		System.out.println(recvBytes + " Bytes Received!");

		//We assume that the HTTP header is smaller than 1K bytes
		//Here we get the HTTP header from the response message
		String responseHeader = "";
		responseHeader = new String(buffer,0,recvBytes);
		//The responseHeaderEndIndex is the index pointing to the begining of the entry body
		int responseHeaderEndIndex = 0;
	       
		responseHeaderEndIndex = /*Fill up*/
		responseHeader = responseHeader.substring(0,responseHeaderEndIndex);

		System.out.println("Entry begins at " + responseHeaderEndIndex);

		System.out.println("<<============Web Server Response Header==========>>");
		//Display the response headers
		System.out.print(responseHeader);
		
		
		//Constuct the forward response headers
		String forwardResponseHeader = "";
		
		tokens = new StringTokenizer(responseHeader,CRLF);
		String responseLine = /*Fill in*/
		Date lastModified = null;
		String lastModifiedLine = "";

		while ( tokens.hasMoreTokens() ) {
	    
		    headerLine = tokens.nextToken();
		    if( headerLine.startsWith("Last-Modified: ") ){
			    /*Fill in*/
		    }
	   	    // Check if it is not a header which the proxy should not forward to
		    if( /*Fill in*/ )
			forwardResponseHeader = forwardResponseHeader + headerLine + CRLF;			    	      
		}			
		forwardResponseHeader += "Connection: close" + CRLF;
		forwardResponseHeader += "Proxy-Connection: close" + CRLF;
			

		boolean notModified=false;
		if( /*Fill in*/ )
		    notModified=true;

		if( !notModified ){
		    
		    System.out.println("<==========Forward Respone Header==================>");
		    System.out.print(responseLine + CRLF + forwardResponseHeader);
		    

		    //Forward the the response headers
			/*Fill in*/

		    //Forward the entry body
		    if( (recvBytes - responseHeaderEndIndex) > 0 ){ 
			System.out.println("Sending Content - "+/*Fill in*/+
					   " Bytes from index "+responseHeaderEndIndex);
			ps.write(/*Fill in*/);
		        while( (recvBytes=/*Fill in*/)>0 ){
			    System.out.println("Sending Content - "+recvBytes+" Bytes");
			    ps.write(/*Fill in*/);
			}			
		    }
		}else{

		    /*Ask to fill*/
		    //304 - Not Modified	       
		    System.out.println("<==========Forward Respone Header==================>");
		    String statusLine = /*Fill in*/
		    String headerLines = /*Fill in*/ 
		    System.out.print(statusLine+headerLines);
		    ps.print(statusLine+headerLines+CRLF);

		}

		System.out.println("<=============Request Processed Sucessfully==============>");

		webServSocket.close();
		
	    }else{
		//502 Cannot receive from the host
		/*Fill in*/
		return;		
	    }
	    
	    
	}else{	    
	    //501 Not Implemented: send reponse code and exit
	    /*Fill in*/
	    return;
	}


	// Close streams and socket.
	ps.close();
	br.close();
	socket.close();

    }


    private void sendResponse(PrintStream ps,int code,String responseMesg) throws Exception	{    
	
	String statusLine="";
	String contentTypeLine="";
	String entityBody="";


	if( code==501 ){
	    statusLine = /*Fill in*/
	    contentTypeLine = /*Fill in*/
	    entityBody = "<HTML>" + 
		"<HEAD><TITLE>501 Not Implemented</TITLE></HEAD>" +
		"<BODY><H1>Not Implemented</H1>"+
		responseMesg +
		"</BODY></HTML>"+CRLF;
	}
	else if( code==502 ){
	    /*Fill in*/
	}

	ps.print(statusLine);
	ps.print(contentTypeLine);
	ps.print(entityBody);

    }

    //Function to parse string to Date object
    //Pls read RFC 2616 Sec3.3
    private Date parseDate(String date){

	StringTokenizer tokens = new StringTokenizer(date," ,");
	int numTokens = tokens.countTokens();
	Date retDate = null;

	if( /*Fill in*/ )
	    return null;

	SimpleDateFormat df=null;

	/*Ask to fill*/
	if(numTokens==6 ) //RFC 822 
	    df = /*Fill in*/
	else if( numTokens==4 ) //RFC 850 
	    df = /*Fill in*/
	else // ANSI C 
	    df = /*Fill in*/

	try{
	    retDate=/*Fill in*/
	}catch( Exception e ){
	    System.out.println(e);
	    retDate=null;
	}

	return retDate;
    }



}
