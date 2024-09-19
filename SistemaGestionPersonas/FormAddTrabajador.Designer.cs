namespace SistemaGestionPersonas
{
    partial class FormAddTrabajador
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.textBox4 = new System.Windows.Forms.TextBox();
            this.textBox5 = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.tableLayoutPanel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.ColumnCount = 3;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.tableLayoutPanel1.Controls.Add(this.textBox5, 1, 1);
            this.tableLayoutPanel1.Controls.Add(this.textBox4, 0, 1);
            this.tableLayoutPanel1.Controls.Add(this.textBox3, 2, 0);
            this.tableLayoutPanel1.Controls.Add(this.textBox2, 1, 0);
            this.tableLayoutPanel1.Controls.Add(this.textBox1, 0, 0);
            this.tableLayoutPanel1.Controls.Add(this.button1, 2, 1);
            this.tableLayoutPanel1.Location = new System.Drawing.Point(12, 12);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 2;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(776, 426);
            this.tableLayoutPanel1.TabIndex = 0;
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(3, 3);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(100, 20);
            this.textBox1.TabIndex = 0;
            this.textBox1.Text = "Nombre";
            this.textBox1.MouseClick += new System.Windows.Forms.MouseEventHandler(this.textBox1_MouseClick);
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(261, 3);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(100, 20);
            this.textBox2.TabIndex = 1;
            this.textBox2.Text = "Edad";
            this.textBox2.MouseClick += new System.Windows.Forms.MouseEventHandler(this.textBox2_MouseClick);
            // 
            // textBox3
            // 
            this.textBox3.Location = new System.Drawing.Point(519, 3);
            this.textBox3.Name = "textBox3";
            this.textBox3.Size = new System.Drawing.Size(100, 20);
            this.textBox3.TabIndex = 2;
            this.textBox3.Text = "Genero";
            this.textBox3.MouseClick += new System.Windows.Forms.MouseEventHandler(this.textBox3_MouseClick);
            // 
            // textBox4
            // 
            this.textBox4.Location = new System.Drawing.Point(3, 216);
            this.textBox4.Name = "textBox4";
            this.textBox4.Size = new System.Drawing.Size(100, 20);
            this.textBox4.TabIndex = 3;
            this.textBox4.Text = "Departamento";
            this.textBox4.MouseClick += new System.Windows.Forms.MouseEventHandler(this.textBox4_MouseClick);
            // 
            // textBox5
            // 
            this.textBox5.Location = new System.Drawing.Point(261, 216);
            this.textBox5.Name = "textBox5";
            this.textBox5.Size = new System.Drawing.Size(100, 20);
            this.textBox5.TabIndex = 4;
            this.textBox5.Text = "Horas trabajadas";
            this.textBox5.MouseClick += new System.Windows.Forms.MouseEventHandler(this.textBox5_MouseClick);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(519, 216);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(254, 53);
            this.button1.TabIndex = 5;
            this.button1.Text = "Agregar trabajador";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // FormAddTrabajador
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.tableLayoutPanel1);
            this.Name = "FormAddTrabajador";
            this.Text = "FormAddTrabajador";
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tableLayoutPanel1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.TextBox textBox5;
        private System.Windows.Forms.TextBox textBox4;
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Button button1;
    }
}