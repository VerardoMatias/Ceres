void checkBack()
{
  back_buttonState = digitalRead(Back_buttonPin);

  // compare the buttonState to its previous state
  if (back_buttonState != back_lastButtonState) {
    // if the state has changed, increment the counter
    if (back_buttonState == LOW) {
      bPress = true;
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter--;

      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  back_lastButtonState = back_buttonState;
}
