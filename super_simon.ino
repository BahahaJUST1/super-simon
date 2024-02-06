#define BLU_LED 32
#define GRN_LED 25
#define YEL_LED 27
#define RED_LED 12

#define BLU_BTN 33
#define GRN_BTN 26
#define YEL_BTN 14
#define RED_BTN 13


int last_choice = 0;

int tableau_simon[10] = {};
int tableau_joueur[10] = {}; 



void game()
{
    for (int i = 0; i < 10; i++) {
        tableau_simon[i] = random(1, 5);
        delay(500);
    }
    
    Serial.println("Contenu du tableau :");
    for (int i = 0; i < 10; i++) {
        Serial.print(tableau_simon[i]);
        Serial.print(" ");
    }
    Serial.println();
}


void setup()
{
    Serial.begin(115200);

    pinMode(BLU_LED, OUTPUT);
    pinMode(GRN_LED, OUTPUT);
    pinMode(YEL_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);

    pinMode(BLU_BTN, INPUT_PULLUP);
    pinMode(GRN_BTN, INPUT_PULLUP);
    pinMode(YEL_BTN, INPUT_PULLUP);
    pinMode(RED_BTN, INPUT_PULLUP);

    game();
}

void loop()
{
    byte blu_btn_val = digitalRead(BLU_BTN);
    byte grn_btn_val = digitalRead(GRN_BTN);
    byte yel_btn_val = digitalRead(YEL_BTN);
    byte red_btn_val = digitalRead(RED_BTN);


    // ====== BLEU ======//
    if (blu_btn_val == LOW) {
        digitalWrite(BLU_LED, HIGH);
        last_choice = 1;
    }
    else {
        digitalWrite(BLU_LED, LOW);
    }


    // ====== VERT ======//
    if (grn_btn_val == LOW) {
        digitalWrite(GRN_LED, HIGH);
        last_choice = 2;
    }
    else {
        digitalWrite(GRN_LED, LOW);
    }


    // ====== JAUNE ======//
    if (yel_btn_val == LOW) {
        digitalWrite(YEL_LED, HIGH);
        last_choice = 3;
    }
    else {
        digitalWrite(YEL_LED, LOW);
    }


    // ====== ROUGE ======//
    if (red_btn_val == LOW) {
        digitalWrite(RED_LED, HIGH);
        last_choice = 4;
    }
    else {
        digitalWrite(RED_LED, LOW);
    }
}