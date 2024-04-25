package buoi3;

import java.io.*;
import java.net.*;
import java.util.Scanner;

import thread.ReceiveMessage;
import thread.SendMessage;

public class clientUDP_SimpleChat {
	public static void main(String[] args) {
		try {
			DatagramSocket ds = new DatagramSocket();
			SendMessage sm = new SendMessage(ds);
			ReceiveMessage rm = new ReceiveMessage(ds);
			sm.start();
			rm.start();
		} catch (SocketException e) {
			
		}
	}
}
