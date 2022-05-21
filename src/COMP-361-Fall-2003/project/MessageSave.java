import java.io.*;
import java.util.*;
import java.text.*;

/**
 * Mail message.
 */
public class MessageSave {

	private static final String CRLF = "\r\n";

    public MessageSave(String from,String to,String raw) {

		/* Sender, recipient and body of the message. */
		String From=from;
		String To=to;
		String Body="From: "+From+CRLF+"To: "+To+CRLF;

		/* Create an buffered reader for the message body */
		BufferedReader Data=new BufferedReader(new StringReader(raw));
		try {
			Data.mark(raw.length());
		}catch (IOException e) {
			System.out.println(e);
		}

		/* Declare the Variable*/
		boolean base64Encoded=false;
		boolean _7bitEncoded=false;
		boolean mime=false;
		boolean multipart=false;
		boolean contentType=false;
		boolean plainText=false;
		boolean isHeader=true;
		boolean isMultiLine=false;
		String boundary="";
		String encodedBody="";
		String directory=FindVacancy("");
		String attachment="";
		String fileName="";
		FileOutputStream file;

		/* Create the directory for this Email */
		(new File(directory)).mkdir();

		/* Read the message header for the parameters used in this Email */
		try {
			while ( Data.read()>0 ) {
				Data.reset();
				String dataLine=Data.readLine();
				Data.mark(raw.length());

				encodedBody+=dataLine+CRLF;

				/* Save the Subject and Date to the message.txt */
				if (dataLine.matches(/* Fill in */) || dataLine.matches(/* Fill in */)) Body+=dataLine+CRLF;

				/* Break the while loop if all the header lines have been processed */
				else if (dataLine.equals(/* Fill in */) || !isHeader ) break;

				/* Check all the tags in Content-Type (may be multiple line)*/
				else if (dataLine.matches(/* Fill in */) || contentType) {

					if (!contentType) {

						/* Set up the flag to indicate Content-Type is processing */
						contentType=/* Fill in */;

						/* Crop the "Content-Type:" head */
						/* Fill in */
					}

					/* If all the Content-Type tags is read, put down the flag */
					else if (!dataLine.matches(/* Fill in */)) contentType=false;

					/* Parse the tags with String Tokenizer */
					StringTokenizer attribute=new StringTokenizer(dataLine,/* Fill in */);
					while ( attribute.hasMoreTokens() ) {
						String parameter=attribute.nextToken().trim();

						/* Check if this tag talks about boundary */
						if ( parameter.matches(/* Fill in */) ) {
							boundary = /* Fill in */;
						}

						/* Check if this tag talks about multipart */
						if ( parameter.equals(/* Fill in */) ) multipart=true;
						/* Check if this tag talks about text/plain */
						if ( parameter.equals(/* Fill in */) ) plainText=true;
					}
				}

				else if (dataLine.matches("Content-Transfer-Encoding:.*")) {

					/* Check if base64 coding is used in message.txt */
					if (dataLine.matches(/* Fill in */)) base64Encoded=/* Fill in */;

					/* Check if 7bit coding is used in message.txt */
					else if (dataLine.matches(/* Fill in */)) _7bitEncoded/* Fill in */;

				}

				/* Check if MIME is enabled in this Email */
				else if (dataLine.matches(/* Fill in */)) mime=/* Fill in */;

				/* Check if invalid header field exist, if yes, it means that this is not header */
				else if ( !(dataLine.matches(/* Fill in */) || dataLine.matches(/* Fill in */) ||
						dataLine.matches(/* Fill in */) || dataLine.matches(/* Fill in */) ||
						dataLine.matches(/* Fill in */) || dataLine.matches(/* Fill in */) ||
						isMultiLine)) isHeader=/* Fill in */;

				/* Check if this header consists of multiple line */
				if ( dataLine.matches(/* Fill in */))  isMultiLine=/* Fill in */; 
				else { isMultiLine=/* Fill in */; }
			}
		}catch (IOException e) {
			System.out.println("Header read error: "+e);
		}


		Body+="-------------------------------------------------"+CRLF;

		if (isHeader) encodedBody="";

		/* This while loop crops the non-MIME parts in MIME email */
		try {
			while ( Data.read()>0 ) {
				Data.reset();
				String dataLine=Data.readLine();
				Data.mark(raw.length());


				/* Check if we meet the boundary in MIME message */
				if ( /* Fill in */ && (dataLine.matches(/* Fill in */) ||
					 dataLine.matches(/* Fill in */)) ) break;

				/* if the Email is non-MIME, Single Part or without header, save the body */
				encodedBody+=/* Fill in */;
			}
		}catch (IOException e) {
			System.out.println("Message read error: "+e);
		}

		/* Do it only if the Email is non-MIME, Single Part or without header */
		if ( /* Fill in */ || /* Fill in */ || /* Fill in */ ) {

			/* If it is base64 encoded, decode it and place it at message.txt */
			if (/* Fill in */ && /* Fill in */) Body+=/* Fill in */;
			else Body+=/* Fill in */;
		}


		/* This block is only for Multipart Message */
		else {

			/* A flag to indicate header is processing */
			boolean header=true;

			/* A flag to indicate MIME-style message.txt is filled or not */
			boolean bodyFilled=false;

			/* Reset the encodedBody */
			encodedBody="";

			/* This while loop loops for each part */
			try {
				while ( Data.read()>0 ) {
					Data.reset();
					String dataLine=Data.readLine();
					Data.mark(raw.length());

					/* We are processing MIME header */
					if (/* Fill in */) {

						/* Turn down the flag if all header is processed */
						if (dataLine.equals(/* Fill in */)) header=/* Fill in */;

						/* Check the Content-Type tags, Same as above */
						else if (dataLine.matches(/* Fill in */) || contentType) {
							if (!contentType) {
								contentType=/* Fill in */;
								/* Fill in */
							}
							else if (!dataLine.matches(/* Fill in */)) contentType=/* Fill in */;

							StringTokenizer attribute=new StringTokenizer(dataLine,";");
							while ( attribute.hasMoreTokens() ) {
								String parameter=attribute.nextToken();

								/* We get the filename of this attachment */
								if ( parameter.matches(/* Fill in */) ) {
									fileName = /* Fill in */;
								}

								/* If this part is text/plain or not */
								if ( parameter.matches(/* Fill in */) ) plainText=/* Fill in */;
							}
						}
						/* Check the supported encoding method (base64/7bit) and set the corresponding flags */
						else if (dataLine.matches(/* Fill in */)) /* Fill in */;
						else if (dataLine.matches(/* Fill in */)) /* Fill in */;
					}

					/* We hit the boundary, it is the time to save the attachment */
					else if (dataLine.matches(/* Fill in */) || dataLine.matches(/* Fill in */)) {

						/* If this part is using un-supported encoding method */
						if (!_7bitEncoded && !base64Encoded) {

							/* If this part doesn't give the filename, use "Attachment" as default */
							if (fileName.equals("")) fileName="Attachment";

							/* Check if redundant file exist */
							fileName=FindVacancy(/* Fill in */);

							/* Display a line in message.txt to indicate this attachment encounters problem */
							attachment+=fileName.substring(fileName.lastIndexOf('\\')+1)+" (discarded due to unknown encoding method)"+CRLF;
						}

						/* If this part is the MIME-style message.txt 
						   (This part should be no attachment filename and text/plain) */
						else if (/* Fill in */ && /* Fill in */ && fileName.equals(/* Fill in */)) {
							bodyFilled=true;
							if (base64Encoded) Body+=/* Fill in */;
							else Body+=/* Fill in */;
						}

						/* For other supported attachment, process it here */
						else {
							if (fileName.equals("")) fileName="Attachment";
							fileName=FindVacancy(directory+'/'+fileName);

							/* Create a new FileOutputStream for writing */
							file = new FileOutputStream(fileName);
							if (base64Encoded) file.write(/* Fill in */);
							else file.write(/* Fill in */);

							/* Close the file */
							file.close();

							/* Display a line in message.txt to indicate this attachment */
							attachment+=fileName.substring(fileName.lastIndexOf('\\')+1)+CRLF;
						}

						/* Reset the necessary flags and variable for next part */
						base64Encoded=false;
						_7bitEncoded=false;
						plainText=false;
						header=true;
						encodedBody="";
						fileName="";
					}

					/* In normal case, just accumulate the string read */
					else encodedBody+=/* Fill in */;
				}
			}catch (IOException e) {
				System.out.println("MIME part error: "+e);
			}


		}

		/* Finally we save the message.txt */
		/* Append the attachment information at the end of the message.txt */
		if (multipart && mime) 
			Body+="-------------------------------------------------"+CRLF+"File(s) of Attachment :"+CRLF+attachment;

		/* Open a the message.txt file and write it */
		try {
			file = new FileOutputStream(FindVacancy(directory+"/message.txt"));
			file.write(/* Fill in */);

			/* Close the file */
			file.close();
		} catch (FileNotFoundException e) {
			System.out.println("File save error: "+e);
		} catch (IOException e) {
			System.out.println("File save error: "+e);
		} catch (Exception e) {
			System.out.println("File save error: "+e);
		}

	}

	/* This method find out the next available directory/file name */
    public static String FindVacancy (String prefix) {

		int counter=0;
		String extension="";
		File entry;
		NumberFormat nf = NumberFormat.getInstance();
		nf.setMinimumIntegerDigits(2);

		if (prefix.equals("")) entry = new File(Today()+'_'+nf.format(counter));
		else entry = new File(prefix);

		if (prefix.lastIndexOf('.') >= 0) {
			extension=prefix.substring(prefix.lastIndexOf('.'));
			prefix=prefix.substring(0,prefix.lastIndexOf('.'));
		}

		while (entry.exists()) {
			counter++;
			if (prefix.equals("")) entry = new File(Today()+'_'+nf.format(counter));
			else entry = new File(prefix+'_'+nf.format(counter)+extension);
		}

		return entry.toString();
	}

	/* This method return the date in simple DDMMM format */
	private static String Today() {
		String[] month = {"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"};
		Calendar today = Calendar.getInstance();
		return today.get(Calendar.DATE)+month[today.get(Calendar.MONTH)];
	}
}
