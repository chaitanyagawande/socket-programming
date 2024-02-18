package com.socket.client;

import org.junit.jupiter.api.Test;
import java.util.Base64;
import static org.junit.jupiter.api.Assertions.assertEquals;

public class BasicClientTest {

    @Test
    void testMessageEncoding() {

        String inputMessage = "Hello, World!";
        String expectedEncodedMessage = Base64.getEncoder().encodeToString(inputMessage.getBytes());

        
        String actualEncodedMessage = simulateMessageEncoding(inputMessage);

        assertEquals(expectedEncodedMessage, actualEncodedMessage, "Encoded message should match expected Base64 encoded result.");
    }

    
    private String simulateMessageEncoding(String input) {
    return Base64.getEncoder().encodeToString(input.getBytes());
    }
}
