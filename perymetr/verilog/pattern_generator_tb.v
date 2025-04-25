module pattern_generator_tb;
    // Sygnały testowe
    reg clk;
    reg rst;
    reg [7:0] brightness;
    reg [7:0] speed;
    wire [7:0] pattern_0;
    wire [7:0] pattern_1;
    wire [7:0] pattern_2;
    wire [7:0] pattern_3;
    wire [7:0] pattern_4;
    wire [7:0] pattern_5;
    wire [7:0] pattern_6;
    wire [7:0] pattern_7;
    wire pattern_valid;
    
    // Instancja modułu testowanego
    pattern_generator dut(
        .clk(clk),
        .rst(rst),
        .brightness(brightness),
        .speed(speed),
        .pattern_0(pattern_0),
        .pattern_1(pattern_1),
        .pattern_2(pattern_2),
        .pattern_3(pattern_3),
        .pattern_4(pattern_4),
        .pattern_5(pattern_5),
        .pattern_6(pattern_6),
        .pattern_7(pattern_7),
        .pattern_valid(pattern_valid)
    );
    
    // Generowanie zegara
    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end
    
    // Testy
    initial begin
        // Inicjalizacja
        rst = 1;
        brightness = 8'hFF;
        speed = 8'h10;
        #20;
        
        // Reset
        rst = 0;
        #20;
        
        // Test 1: Sprawdzenie pierwszego wzorca
        #100;
        if (pattern_0 == 8'h18) $display("Test 1: PASSED");
        else $display("Test 1: FAILED");
        
        // Test 2: Zmiana jasności
        brightness = 8'h0F;
        #100;
        if (pattern_0 == 8'h08) $display("Test 2: PASSED");
        else $display("Test 2: FAILED");
        
        // Test 3: Zmiana prędkości
        speed = 8'h05;
        #50;
        if (pattern_valid) $display("Test 3: PASSED");
        else $display("Test 3: FAILED");
        
        // Test 4: Reset w trakcie działania
        rst = 1;
        #20;
        rst = 0;
        #20;
        if (pattern_valid == 0) $display("Test 4: PASSED");
        else $display("Test 4: FAILED");
        
        // Koniec symulacji
        #100;
        $finish;
    end
    
    // Monitorowanie zmian
    initial begin
        $monitor("Time=%t rst=%b brightness=%h speed=%h pattern_valid=%b pattern_0=%h",
                 $time, rst, brightness, speed, pattern_valid, pattern_0);
    end

endmodule 