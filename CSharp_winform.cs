
https://vualaptrinh.blogspot.com/search/label/C%23%20Winform%20c%C4%83n%20b%E1%BA%A3n
https://csharpcanban.com/c-sharp-lap-trinh-winform-toan-tap
http://thuvienwinform.blogspot.com/

http://www.vboxjapan.co.jp/VBOX/support/Manual/CAN02_Manual_Japanese.pdf

https://www.youtube.com/watch?v=lxbUcU4Q5Fk

****************************************Input number only to textBox ******************************************************

public Form1()
{
	InitializeComponent();


	//enableMDI();
	createTreeview();

	//textBox1.KeyDown += TextBox1_KeyDown;
	textBox1.KeyPress += TextBox1_KeyPress;
	//textBox1.KeyUp += TextBox1_KeyUp;

}

//// Handle the KeyUp event to print the type of character entered into the control.
//private void TextBox1_KeyUp(object sender, KeyEventArgs e)
//{
//    Debug.WriteLine($"KeyUp code: {e.KeyCode}, value: {e.KeyValue}, modifiers: {e.Modifiers}" + "\r\n");
//}

// Handle the KeyPress event to print the type of character entered into the control.
//private void TextBox1_KeyPress(object sender, KeyPressEventArgs e)
//{
//    //Debug.WriteLine($"KeyPress keychar: {e.KeyChar}" + "\r\n");
//    Debug.WriteLine(e.KeyChar);
//    //allows backspace key
//    if (e.KeyChar != '\b')
//    {
//        //allows just number keys
//        e.Handled = !char.IsNumber(e.KeyChar);
//    }
//}


private void TextBox1_KeyPress(object sender, KeyPressEventArgs e)
{
	if (!char.IsControl(e.KeyChar) && !char.IsDigit(e.KeyChar) && (e.KeyChar != '.'))
	{
		e.Handled = true;
	}
}

private void textBox1_TextChanged(object sender, EventArgs e)
{
	if (System.Text.RegularExpressions.Regex.IsMatch(textBox1.Text, "  ^ [0-9]"))
	{
		textBox1.Text = "";
	}
}