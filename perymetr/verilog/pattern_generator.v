module pattern_generator(
    input wire clk,
    input wire rst,
    input wire [7:0] brightness,
    input wire [7:0] speed,
    output reg [7:0] pattern_0,
    output reg [7:0] pattern_1,
    output reg [7:0] pattern_2,
    output reg [7:0] pattern_3,
    output reg [7:0] pattern_4,
    output reg [7:0] pattern_5,
    output reg [7:0] pattern_6,
    output reg [7:0] pattern_7,
    output reg pattern_valid
);

    // Parametry
    parameter PATTERN_COUNT = 8;
    
    // Rejestry
    reg [2:0] pattern_index;
    reg [31:0] counter;
    reg [7:0] current_pattern_0;
    reg [7:0] current_pattern_1;
    reg [7:0] current_pattern_2;
    reg [7:0] current_pattern_3;
    reg [7:0] current_pattern_4;
    reg [7:0] current_pattern_5;
    reg [7:0] current_pattern_6;
    reg [7:0] current_pattern_7;
    
    // Inicjalizacja wzorców
    initial begin
        pattern_index = 0;
        counter = 0;
        pattern_valid = 0;
        
        // Wzorzec 0: Krzyż
        current_pattern_0 = 8'b00011000;
        current_pattern_1 = 8'b00011000;
        current_pattern_2 = 8'b00011000;
        current_pattern_3 = 8'b11111111;
        current_pattern_4 = 8'b11111111;
        current_pattern_5 = 8'b00011000;
        current_pattern_6 = 8'b00011000;
        current_pattern_7 = 8'b00011000;
        
        // Inicjalizacja wyjść
        pattern_0 = current_pattern_0 & brightness;
        pattern_1 = current_pattern_1 & brightness;
        pattern_2 = current_pattern_2 & brightness;
        pattern_3 = current_pattern_3 & brightness;
        pattern_4 = current_pattern_4 & brightness;
        pattern_5 = current_pattern_5 & brightness;
        pattern_6 = current_pattern_6 & brightness;
        pattern_7 = current_pattern_7 & brightness;
    end
    
    // Logika generowania wzorców
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            pattern_index <= 0;
            counter <= 0;
            pattern_valid <= 0;
            
            // Reset wzorców
            pattern_0 <= current_pattern_0 & brightness;
            pattern_1 <= current_pattern_1 & brightness;
            pattern_2 <= current_pattern_2 & brightness;
            pattern_3 <= current_pattern_3 & brightness;
            pattern_4 <= current_pattern_4 & brightness;
            pattern_5 <= current_pattern_5 & brightness;
            pattern_6 <= current_pattern_6 & brightness;
            pattern_7 <= current_pattern_7 & brightness;
        end else begin
            // Aktualizacja licznika
            if (counter >= speed) begin
                counter <= 0;
                pattern_index <= pattern_index + 1;
                if (pattern_index == PATTERN_COUNT-1)
                    pattern_index <= 0;
                    
                // Aktualizacja wzorca
                pattern_0 <= current_pattern_0 & brightness;
                pattern_1 <= current_pattern_1 & brightness;
                pattern_2 <= current_pattern_2 & brightness;
                pattern_3 <= current_pattern_3 & brightness;
                pattern_4 <= current_pattern_4 & brightness;
                pattern_5 <= current_pattern_5 & brightness;
                pattern_6 <= current_pattern_6 & brightness;
                pattern_7 <= current_pattern_7 & brightness;
                        
                pattern_valid <= 1;
            end else begin
                counter <= counter + 1;
                if (counter == speed-1)
                    pattern_valid <= 0;
            end
        end
    end

endmodule 