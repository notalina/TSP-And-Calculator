#pragma once
#include<cmath>

namespace Calculator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>Calculator::MyForm
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txtDisplay;
	protected:





	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::Button^ buttonOne;
	private: System::Windows::Forms::Button^ buttonTwo;
	private: System::Windows::Forms::Button^ buttonThree;
	private: System::Windows::Forms::Button^ buttonFour;
	private: System::Windows::Forms::Button^ buttonFive;
	private: System::Windows::Forms::Button^ buttonSix;
	private: System::Windows::Forms::Button^ buttonSeven;
	private: System::Windows::Forms::Button^ buttonEight;
	private: System::Windows::Forms::Button^ buttonNine;
	private: System::Windows::Forms::Button^ buttonZero;
	private: System::Windows::Forms::Button^ buttonDot;
	private: System::Windows::Forms::Button^ buttonExponent;













	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel2;
	private: System::Windows::Forms::Button^ buttonMinus;
	private: System::Windows::Forms::Button^ buttonPlus;
	private: System::Windows::Forms::Button^ buttonMultiply;
	private: System::Windows::Forms::Button^ buttonDivision;
	private: System::Windows::Forms::Button^ clearMainTextBox;






	private: System::Windows::Forms::Button^ equalityButton;
	private: System::Windows::Forms::Button^ logarithmLN;

	private: System::Windows::Forms::Button^ logaritm10;
	private: System::Windows::Forms::Button^ complicatedLogarithm;


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBoxA;
	private: System::Windows::Forms::TextBox^ textBoxB;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lblCorner;
	private: System::Windows::Forms::Button^ power;








	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->txtDisplay = (gcnew System::Windows::Forms::TextBox());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->buttonOne = (gcnew System::Windows::Forms::Button());
			this->buttonTwo = (gcnew System::Windows::Forms::Button());
			this->buttonThree = (gcnew System::Windows::Forms::Button());
			this->buttonFour = (gcnew System::Windows::Forms::Button());
			this->buttonFive = (gcnew System::Windows::Forms::Button());
			this->buttonSix = (gcnew System::Windows::Forms::Button());
			this->buttonSeven = (gcnew System::Windows::Forms::Button());
			this->buttonEight = (gcnew System::Windows::Forms::Button());
			this->buttonNine = (gcnew System::Windows::Forms::Button());
			this->buttonZero = (gcnew System::Windows::Forms::Button());
			this->buttonDot = (gcnew System::Windows::Forms::Button());
			this->buttonExponent = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->buttonMinus = (gcnew System::Windows::Forms::Button());
			this->buttonPlus = (gcnew System::Windows::Forms::Button());
			this->buttonMultiply = (gcnew System::Windows::Forms::Button());
			this->buttonDivision = (gcnew System::Windows::Forms::Button());
			this->clearMainTextBox = (gcnew System::Windows::Forms::Button());
			this->equalityButton = (gcnew System::Windows::Forms::Button());
			this->logarithmLN = (gcnew System::Windows::Forms::Button());
			this->logaritm10 = (gcnew System::Windows::Forms::Button());
			this->complicatedLogarithm = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBoxA = (gcnew System::Windows::Forms::TextBox());
			this->textBoxB = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblCorner = (gcnew System::Windows::Forms::Label());
			this->power = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// txtDisplay
			// 
			this->txtDisplay->BackColor = System::Drawing::Color::White;
			this->txtDisplay->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtDisplay->ForeColor = System::Drawing::SystemColors::InfoText;
			this->txtDisplay->Location = System::Drawing::Point(22, 22);
			this->txtDisplay->Multiline = true;
			this->txtDisplay->Name = L"txtDisplay";
			this->txtDisplay->Size = System::Drawing::Size(325, 29);
			this->txtDisplay->TabIndex = 4;
			this->txtDisplay->Text = L"0";
			this->txtDisplay->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->BackColor = System::Drawing::Color::Transparent;
			this->flowLayoutPanel1->Controls->Add(this->buttonOne);
			this->flowLayoutPanel1->Controls->Add(this->buttonTwo);
			this->flowLayoutPanel1->Controls->Add(this->buttonThree);
			this->flowLayoutPanel1->Controls->Add(this->buttonFour);
			this->flowLayoutPanel1->Controls->Add(this->buttonFive);
			this->flowLayoutPanel1->Controls->Add(this->buttonSix);
			this->flowLayoutPanel1->Controls->Add(this->buttonSeven);
			this->flowLayoutPanel1->Controls->Add(this->buttonEight);
			this->flowLayoutPanel1->Controls->Add(this->buttonNine);
			this->flowLayoutPanel1->Controls->Add(this->buttonZero);
			this->flowLayoutPanel1->Controls->Add(this->buttonDot);
			this->flowLayoutPanel1->Controls->Add(this->buttonExponent);
			this->flowLayoutPanel1->Location = System::Drawing::Point(22, 61);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(150, 143);
			this->flowLayoutPanel1->TabIndex = 5;
			// 
			// buttonOne
			// 
			this->buttonOne->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonOne->Location = System::Drawing::Point(3, 3);
			this->buttonOne->Name = L"buttonOne";
			this->buttonOne->Size = System::Drawing::Size(42, 29);
			this->buttonOne->TabIndex = 0;
			this->buttonOne->Text = L"1";
			this->buttonOne->UseVisualStyleBackColor = true;
			this->buttonOne->Click += gcnew System::EventHandler(this, &MyForm::buttonClick);
			// 
			// buttonTwo
			// 
			this->buttonTwo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonTwo->Location = System::Drawing::Point(51, 3);
			this->buttonTwo->Name = L"buttonTwo";
			this->buttonTwo->Size = System::Drawing::Size(42, 29);
			this->buttonTwo->TabIndex = 1;
			this->buttonTwo->Text = L"2";
			this->buttonTwo->UseVisualStyleBackColor = true;
			this->buttonTwo->Click += gcnew System::EventHandler(this, &MyForm::buttonClick);
			// 
			// buttonThree
			// 
			this->buttonThree->BackColor = System::Drawing::Color::Transparent;
			this->buttonThree->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonThree->Location = System::Drawing::Point(99, 3);
			this->buttonThree->Name = L"buttonThree";
			this->buttonThree->Size = System::Drawing::Size(42, 29);
			this->buttonThree->TabIndex = 2;
			this->buttonThree->Text = L"3";
			this->buttonThree->UseVisualStyleBackColor = false;
			this->buttonThree->Click += gcnew System::EventHandler(this, &MyForm::buttonClick);
			// 
			// buttonFour
			// 
			this->buttonFour->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonFour->Location = System::Drawing::Point(3, 38);
			this->buttonFour->Name = L"buttonFour";
			this->buttonFour->Size = System::Drawing::Size(42, 29);
			this->buttonFour->TabIndex = 3;
			this->buttonFour->Text = L"4";
			this->buttonFour->UseVisualStyleBackColor = true;
			this->buttonFour->Click += gcnew System::EventHandler(this, &MyForm::buttonClick);
			// 
			// buttonFive
			// 
			this->buttonFive->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonFive->Location = System::Drawing::Point(51, 38);
			this->buttonFive->Name = L"buttonFive";
			this->buttonFive->Size = System::Drawing::Size(42, 29);
			this->buttonFive->TabIndex = 4;
			this->buttonFive->Text = L"5";
			this->buttonFive->UseVisualStyleBackColor = true;
			this->buttonFive->Click += gcnew System::EventHandler(this, &MyForm::buttonClick);
			// 
			// buttonSix
			// 
			this->buttonSix->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonSix->Location = System::Drawing::Point(99, 38);
			this->buttonSix->Name = L"buttonSix";
			this->buttonSix->Size = System::Drawing::Size(42, 29);
			this->buttonSix->TabIndex = 5;
			this->buttonSix->Text = L"6";
			this->buttonSix->UseVisualStyleBackColor = true;
			this->buttonSix->Click += gcnew System::EventHandler(this, &MyForm::buttonClick);
			// 
			// buttonSeven
			// 
			this->buttonSeven->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonSeven->Location = System::Drawing::Point(3, 73);
			this->buttonSeven->Name = L"buttonSeven";
			this->buttonSeven->Size = System::Drawing::Size(42, 29);
			this->buttonSeven->TabIndex = 6;
			this->buttonSeven->Text = L"7";
			this->buttonSeven->UseVisualStyleBackColor = true;
			this->buttonSeven->Click += gcnew System::EventHandler(this, &MyForm::buttonClick);
			// 
			// buttonEight
			// 
			this->buttonEight->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonEight->Location = System::Drawing::Point(51, 73);
			this->buttonEight->Name = L"buttonEight";
			this->buttonEight->Size = System::Drawing::Size(42, 29);
			this->buttonEight->TabIndex = 7;
			this->buttonEight->Text = L"8";
			this->buttonEight->UseVisualStyleBackColor = true;
			this->buttonEight->Click += gcnew System::EventHandler(this, &MyForm::buttonClick);
			// 
			// buttonNine
			// 
			this->buttonNine->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonNine->Location = System::Drawing::Point(99, 73);
			this->buttonNine->Name = L"buttonNine";
			this->buttonNine->Size = System::Drawing::Size(42, 29);
			this->buttonNine->TabIndex = 8;
			this->buttonNine->Text = L"9";
			this->buttonNine->UseVisualStyleBackColor = true;
			this->buttonNine->Click += gcnew System::EventHandler(this, &MyForm::buttonClick);
			// 
			// buttonZero
			// 
			this->buttonZero->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonZero->Location = System::Drawing::Point(3, 108);
			this->buttonZero->Name = L"buttonZero";
			this->buttonZero->Size = System::Drawing::Size(42, 29);
			this->buttonZero->TabIndex = 9;
			this->buttonZero->Text = L"0";
			this->buttonZero->UseVisualStyleBackColor = true;
			this->buttonZero->Click += gcnew System::EventHandler(this, &MyForm::buttonClick);
			// 
			// buttonDot
			// 
			this->buttonDot->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonDot->Location = System::Drawing::Point(51, 108);
			this->buttonDot->Name = L"buttonDot";
			this->buttonDot->Size = System::Drawing::Size(43, 29);
			this->buttonDot->TabIndex = 10;
			this->buttonDot->Text = L".";
			this->buttonDot->UseVisualStyleBackColor = true;
			this->buttonDot->Click += gcnew System::EventHandler(this, &MyForm::buttonDot_Click);
			// 
			// buttonExponent
			// 
			this->buttonExponent->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonExponent->Location = System::Drawing::Point(100, 108);
			this->buttonExponent->Name = L"buttonExponent";
			this->buttonExponent->Size = System::Drawing::Size(43, 29);
			this->buttonExponent->TabIndex = 11;
			this->buttonExponent->Text = L"e";
			this->buttonExponent->UseVisualStyleBackColor = true;
			this->buttonExponent->Click += gcnew System::EventHandler(this, &MyForm::buttonExponent_Click);
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->BackColor = System::Drawing::Color::Transparent;
			this->flowLayoutPanel2->Controls->Add(this->buttonMinus);
			this->flowLayoutPanel2->Controls->Add(this->buttonPlus);
			this->flowLayoutPanel2->Controls->Add(this->buttonMultiply);
			this->flowLayoutPanel2->Controls->Add(this->buttonDivision);
			this->flowLayoutPanel2->Location = System::Drawing::Point(178, 61);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(51, 143);
			this->flowLayoutPanel2->TabIndex = 6;
			// 
			// buttonMinus
			// 
			this->buttonMinus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonMinus->Location = System::Drawing::Point(3, 3);
			this->buttonMinus->Name = L"buttonMinus";
			this->buttonMinus->Size = System::Drawing::Size(42, 29);
			this->buttonMinus->TabIndex = 2;
			this->buttonMinus->Text = L"-";
			this->buttonMinus->UseVisualStyleBackColor = true;
			this->buttonMinus->Click += gcnew System::EventHandler(this, &MyForm::minusClick);
			// 
			// buttonPlus
			// 
			this->buttonPlus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonPlus->Location = System::Drawing::Point(3, 38);
			this->buttonPlus->Name = L"buttonPlus";
			this->buttonPlus->Size = System::Drawing::Size(42, 29);
			this->buttonPlus->TabIndex = 3;
			this->buttonPlus->Text = L"+";
			this->buttonPlus->UseVisualStyleBackColor = true;
			this->buttonPlus->Click += gcnew System::EventHandler(this, &MyForm::plusClick);
			// 
			// buttonMultiply
			// 
			this->buttonMultiply->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonMultiply->Location = System::Drawing::Point(3, 73);
			this->buttonMultiply->Name = L"buttonMultiply";
			this->buttonMultiply->Size = System::Drawing::Size(42, 29);
			this->buttonMultiply->TabIndex = 4;
			this->buttonMultiply->Text = L"*";
			this->buttonMultiply->UseVisualStyleBackColor = true;
			this->buttonMultiply->Click += gcnew System::EventHandler(this, &MyForm::multiplyClick);
			// 
			// buttonDivision
			// 
			this->buttonDivision->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonDivision->Location = System::Drawing::Point(3, 108);
			this->buttonDivision->Name = L"buttonDivision";
			this->buttonDivision->Size = System::Drawing::Size(42, 29);
			this->buttonDivision->TabIndex = 6;
			this->buttonDivision->Text = L"/";
			this->buttonDivision->UseVisualStyleBackColor = true;
			this->buttonDivision->Click += gcnew System::EventHandler(this, &MyForm::divideClick);
			// 
			// clearMainTextBox
			// 
			this->clearMainTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->clearMainTextBox->Location = System::Drawing::Point(294, 64);
			this->clearMainTextBox->Name = L"clearMainTextBox";
			this->clearMainTextBox->Size = System::Drawing::Size(53, 29);
			this->clearMainTextBox->TabIndex = 7;
			this->clearMainTextBox->Text = L"C";
			this->clearMainTextBox->UseVisualStyleBackColor = true;
			this->clearMainTextBox->Click += gcnew System::EventHandler(this, &MyForm::clearMainTextClick);
			// 
			// equalityButton
			// 
			this->equalityButton->Location = System::Drawing::Point(235, 64);
			this->equalityButton->Name = L"equalityButton";
			this->equalityButton->Size = System::Drawing::Size(53, 29);
			this->equalityButton->TabIndex = 0;
			this->equalityButton->Text = L"=";
			this->equalityButton->UseVisualStyleBackColor = true;
			this->equalityButton->Click += gcnew System::EventHandler(this, &MyForm::equalityButton_click);
			// 
			// logarithmLN
			// 
			this->logarithmLN->Location = System::Drawing::Point(235, 99);
			this->logarithmLN->Name = L"logarithmLN";
			this->logarithmLN->Size = System::Drawing::Size(53, 29);
			this->logarithmLN->TabIndex = 8;
			this->logarithmLN->Text = L"ln";
			this->logarithmLN->UseVisualStyleBackColor = true;
			this->logarithmLN->Click += gcnew System::EventHandler(this, &MyForm::logarithmLN_Click);
			// 
			// logaritm10
			// 
			this->logaritm10->Location = System::Drawing::Point(235, 134);
			this->logaritm10->Name = L"logaritm10";
			this->logaritm10->Size = System::Drawing::Size(53, 29);
			this->logaritm10->TabIndex = 9;
			this->logaritm10->Text = L"lg";
			this->logaritm10->UseVisualStyleBackColor = true;
			this->logaritm10->Click += gcnew System::EventHandler(this, &MyForm::logaritm10_Click);
			// 
			// complicatedLogarithm
			// 
			this->complicatedLogarithm->Location = System::Drawing::Point(294, 99);
			this->complicatedLogarithm->Name = L"complicatedLogarithm";
			this->complicatedLogarithm->Size = System::Drawing::Size(53, 29);
			this->complicatedLogarithm->TabIndex = 10;
			this->complicatedLogarithm->Text = L"log a (b)";
			this->complicatedLogarithm->UseVisualStyleBackColor = true;
			this->complicatedLogarithm->Click += gcnew System::EventHandler(this, &MyForm::complicatedLogarithm_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(294, 146);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(20, 17);
			this->label2->TabIndex = 12;
			this->label2->Text = L"a:";
			// 
			// textBoxA
			// 
			this->textBoxA->Location = System::Drawing::Point(316, 146);
			this->textBoxA->Name = L"textBoxA";
			this->textBoxA->Size = System::Drawing::Size(31, 20);
			this->textBoxA->TabIndex = 13;
			// 
			// textBoxB
			// 
			this->textBoxB->Location = System::Drawing::Point(316, 175);
			this->textBoxB->Name = L"textBoxB";
			this->textBoxB->Size = System::Drawing::Size(31, 20);
			this->textBoxB->TabIndex = 15;
			this->textBoxB->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(294, 175);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(20, 17);
			this->label1->TabIndex = 14;
			this->label1->Text = L"b:";
			// 
			// lblCorner
			// 
			this->lblCorner->AutoSize = true;
			this->lblCorner->BackColor = System::Drawing::Color::White;
			this->lblCorner->Location = System::Drawing::Point(25, 25);
			this->lblCorner->Name = L"lblCorner";
			this->lblCorner->Size = System::Drawing::Size(0, 13);
			this->lblCorner->TabIndex = 16;
			// 
			// power
			// 
			this->power->Location = System::Drawing::Point(235, 169);
			this->power->Name = L"power";
			this->power->Size = System::Drawing::Size(53, 29);
			this->power->TabIndex = 17;
			this->power->Text = L"^";
			this->power->UseVisualStyleBackColor = true;
			this->power->Click += gcnew System::EventHandler(this, &MyForm::power_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Thistle;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(365, 218);
			this->Controls->Add(this->power);
			this->Controls->Add(this->lblCorner);
			this->Controls->Add(this->textBoxB);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBoxA);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->complicatedLogarithm);
			this->Controls->Add(this->logaritm10);
			this->Controls->Add(this->logarithmLN);
			this->Controls->Add(this->clearMainTextBox);
			this->Controls->Add(this->flowLayoutPanel2);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->txtDisplay);
			this->Controls->Add(this->equalityButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"MyForm";
			this->Text = L"Calculator";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		double pocket; //кармашек для следующих чисел
		double result; //переменная для хранения результатов
		double pwr; //степень
		String^ someOperator; // переменная для хранения знака математического действия
		bool operatorCalledFirstTime = true; //флажок для определения порядка вызова операторов
		bool dotPasted = false; //флажок для определения была ли нажата точка
		bool exponentUsed = false; //флажок для определения была ли использована e
								   
	    //функция вычислений
		double doCalculation(String^ op) {
			if (op == "-") {
				return result -= pocket;
			} else if (op == "+") {
				return result += pocket;
			} else if (op == "*") {
				return result *= pocket;
			} else if (op == "/") {
				return result /= pocket;
			} else if (op == "^") {
				if (result - exp(1) < 0.0000000001) {
					return exp(pocket);
					pwr = pocket;
				}
				else {
					return result = pow(result, pocket);
				}
			}
		}
		//очистка дисплея
private: System::Void clearMainTextClick(System::Object^ sender, System::EventArgs^ e) {
	txtDisplay->Text = "0";
	lblCorner->Text = "";
	pocket = 0;
	result = 0;
	operatorCalledFirstTime = true;
	dotPasted = false;
	exponentUsed = false;
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
	
	   //нажатие на  кнопки цифр

private: System::Void buttonClick(System::Object^ sender, System::EventArgs^ e) {
	Button^ Number = safe_cast<Button^>(sender);
	if (txtDisplay->Text == "0") {
		txtDisplay->Text = Number->Text;
	}
	else {
		txtDisplay->Text = txtDisplay->Text + Number->Text;
	}
}
	   //нажатие на кнопку e
private: System::Void buttonExponent_Click(System::Object^ sender, System::EventArgs^ e) {
	double exponent = exp(1);
	exponentUsed = true;
	if (txtDisplay->Text == "0") {
		txtDisplay->Text = System::Convert::ToString(exponent);
		lblCorner->Text = lblCorner->Text + System::Convert::ToString("e");
	}
}
	   //нажатие на кнопку равенства
private: System::Void equalityButton_click(System::Object^ sender, System::EventArgs^ e) {
	lblCorner->Text = "";
	pocket = Double::Parse(txtDisplay->Text);
	if (pocket != 0) {
		result = doCalculation(someOperator);
	}
	txtDisplay->Text = System::Convert::ToString(result);
	operatorCalledFirstTime = true;
	dotPasted = false;
	exponentUsed = false;
	pocket = 0;
	result = 0;
}
	   //вычитание
private: System::Void minusClick(System::Object^ sender, System::EventArgs^ e) {
	if (operatorCalledFirstTime) {
		if (txtDisplay->Text != "e") {
			result = Double::Parse(txtDisplay->Text);
		}
		txtDisplay->Text = "0";
		dotPasted = false;
		exponentUsed = false;
		lblCorner->Text = System::Convert::ToString(result) + " -";
		operatorCalledFirstTime = false;
		someOperator = "-";
	}
	else {
		pocket = Double::Parse(txtDisplay->Text);
		result = doCalculation(someOperator);
		txtDisplay->Text = "0";
		dotPasted = false;
		exponentUsed = false;
		lblCorner->Text = System::Convert::ToString(result) + " -";
		someOperator = "-";
	}
}
	   //прибавление
private: System::Void plusClick(System::Object^ sender, System::EventArgs^ e) {
	if (operatorCalledFirstTime) {
		if (txtDisplay->Text != "e") {
			result = Double::Parse(txtDisplay->Text);
		}
		txtDisplay->Text = "0";
		dotPasted = false;
		exponentUsed = false;
		lblCorner->Text = System::Convert::ToString(result) + " +";
		operatorCalledFirstTime = false;
		someOperator = "+";
	}
	else {
		pocket = Double::Parse(txtDisplay->Text);
		result = doCalculation(someOperator);
		someOperator = "+";
		lblCorner->Text = System::Convert::ToString(result) + " +";
		txtDisplay->Text = "0";
		dotPasted = false;
		exponentUsed = false;
	}
}
	   //умножение
private: System::Void multiplyClick(System::Object^ sender, System::EventArgs^ e) {
	if (operatorCalledFirstTime) {
		if (txtDisplay->Text != "e") {
			result = Double::Parse(txtDisplay->Text);
		}
		txtDisplay->Text = "0";
		dotPasted = false;
		exponentUsed = false;
		lblCorner->Text = System::Convert::ToString(result) + " *";
		operatorCalledFirstTime = false;
		someOperator = "*";
	}
	else {
		pocket = Double::Parse(txtDisplay->Text);
		result = doCalculation(someOperator);
		txtDisplay->Text = "0";
		dotPasted = false;
		exponentUsed = false;
		lblCorner->Text = System::Convert::ToString(result) + " *";
		someOperator = "*";
	}
}
	   //деление
private: System::Void divideClick(System::Object^ sender, System::EventArgs^ e) {
	if (operatorCalledFirstTime) {
		if (txtDisplay->Text != "e") {
			result = Double::Parse(txtDisplay->Text);
		}
		txtDisplay->Text = "0";
		dotPasted = false;
		exponentUsed = false;
		lblCorner->Text = System::Convert::ToString(result) + " /";
		operatorCalledFirstTime = false;
		someOperator = "/";
	}
	else {
		pocket = Double::Parse(txtDisplay->Text);
		result = doCalculation(someOperator);
		someOperator = "/";
		txtDisplay->Text = "0";
		dotPasted = false;
		exponentUsed = false;
		lblCorner->Text = System::Convert::ToString(result) + " /";
	}
}
	   //десятичный логариф
private: System::Void logaritm10_Click(System::Object^ sender, System::EventArgs^ e) {
	double value = Double::Parse(txtDisplay->Text);
	if (value > 0) {
		value = log10(value);
		txtDisplay->Text = System::Convert::ToString(value);
	}
	else {
		MessageBox::Show("Число должно быть строго больше нуля.");
	}
}
	   //нажатие на кнопку точки
private: System::Void buttonDot_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!dotPasted) {
		txtDisplay->Text = txtDisplay->Text + ".";
		dotPasted = true;
	}
}
	   //возведение в степень
private: System::Void power_Click(System::Object^ sender, System::EventArgs^ e) {
	if (operatorCalledFirstTime) {
		if (txtDisplay->Text != "e") {
			result = Double::Parse(txtDisplay->Text);
		}
		txtDisplay->Text = "0";
		dotPasted = false;
		exponentUsed = false;
		lblCorner->Text = System::Convert::ToString(result) + " ^";
		operatorCalledFirstTime = false;
		someOperator = "^";
	}
	else {
		pocket = Double::Parse(txtDisplay->Text);
		result = doCalculation(someOperator);
		someOperator = "^";
		txtDisplay->Text = "0";
		dotPasted = false;
		exponentUsed = false;
		lblCorner->Text = System::Convert::ToString(result) + " ^";
	}
}
	   //натуральный логарифм
private: System::Void logarithmLN_Click(System::Object^ sender, System::EventArgs^ e) {
	result = Double::Parse(txtDisplay->Text);
	if (result > 0) {
		result = log(result);
		txtDisplay->Text = System::Convert::ToString(result);
	}
	else {
		MessageBox::Show("Число должно быть строго больше нуля.");
	}
}
	   //вычисление логарифма числа number по основанию base
private: System::Void complicatedLogarithm_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textBoxA->Text != "" && textBoxB->Text != "") {
		double base = Double::Parse(textBoxA->Text);
		double number = Double::Parse(textBoxB->Text);
		if ((base == 1) || (base == 0 ) || (base < 0)) {
			MessageBox::Show("Основание логарифма должно быть больше 0 и не равнятся 1.");
		}
		else if (number < 0) {
			MessageBox::Show("Число должно быть больше 0.");
		}
		else if ((base != 1) && (base != 0) && (number > 0)) {
			result = log10(number) / log10(base);
			txtDisplay->Text = System::Convert::ToString(result);
			textBoxA->Text = "";
			textBoxB->Text = "";
		}
	}
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
} 

