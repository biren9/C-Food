package main

import (
	"time"
	"math/rand"

	"fmt"
)

var sign = [18]string{"+", "-", ":", "*", "<", ">", "=", ":=", "=:=", "!", "&&", ";", "(", ")", "{", "}", "[", "]"};
var letter = [52]string{"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"}

func random(min,max int ) int {
	number := rand.Intn(max) + min
	return number

}

func generateToken() {
	randomRows := random(1,25000)
	for i:= 0; i < randomRows; i++ {
		randomTokens := random(1,100) //pro Zeile
		for k:= 0; k < randomTokens; k++ {

			randomLanguage := random(1,20)

			switch {
			case randomLanguage == 1:
				break;
			case randomLanguage > 1 && randomLanguage <= 7:

				break;
			case randomLanguage > 7 && randomLanguage <= 13:
				break;
			case randomLanguage > 13 && randomLanguage <= 19:
				break;
			case randomLanguage == 20:
				k--;
				break;
			}

		}
	}
}

func generateIdentifier() {
	randomLength := random(1,30);

	var identifier string;
	for i := 0; i < randomLength; i++  {
		numberOrLetter := random(1,2)
		if(numberOrLetter == 1 || i == 1 ) {
			randomLetter := random(0,51);
			letter := letter[randomLetter];
			identifier += letter;
		} else {
			number := generateInteger();
			identifier += number;
		}
	}
}

func generateInteger() string {
	randomNumber := random(0,4000000000)

	//10% Chance for secondNumber
	secondNumberChance := random(1,10);
	if secondNumberChance == 1 {
		randomNumber2 := random(0,4000000000)
		number := string(randomNumber) + string(randomNumber2);
		return number;
	} else {
		return string(randomNumber);
	}
}

func generateSign() {
	randomCountRange := random(1,26);

	var lengthSign int;
	switch {
	case randomCountRange > 1 && randomCountRange <= 10:
		lengthSign = 1;
		break;
	case randomCountRange > 10 && randomCountRange <= 17:
		lengthSign = 2;
		break;
	case randomCountRange > 17 && randomCountRange <= 20:
		lengthSign = 3;
		break;
	case randomCountRange > 20 && randomCountRange <= 22:
		lengthSign = 4;
		break;
	case randomCountRange > 22 && randomCountRange <= 23:
		lengthSign = 5;
		break;
	case randomCountRange > 23 && randomCountRange <= 24:
		lengthSign = 6;
		break;
	case randomCountRange > 24 && randomCountRange <= 25:
		lengthSign = 7;
		break;
	case randomCountRange > 25 && randomCountRange <= 26:
		lengthSign = 8;
		break;
	}
	var signWord string;
	//fmt.Println("Length: %d",lengthSign)
	for i := 0; i < lengthSign; i++ {
		randomSign := random(0, 17)
		s := sign[randomSign]
		signWord = signWord + s
	}

	fmt.Println(signWord)
}

func main() {
	rand.Seed(time.Now().Unix())
	for i := 0; i < 30; i++ {
		generateSign()
	}

}

