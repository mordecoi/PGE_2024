namespace JuegoAdivinanza
{
    partial class Form1
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.tbox_intento = new System.Windows.Forms.TextBox();
            this.lab_pista = new System.Windows.Forms.Label();
            this.lab_numeros = new System.Windows.Forms.Label();
            this.btn_adivinar = new System.Windows.Forms.Button();
            this.lab_adivineitor = new System.Windows.Forms.Label();
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.tableLayoutPanel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // tbox_intento
            // 
            this.tbox_intento.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)));
            this.tbox_intento.Location = new System.Drawing.Point(338, 88);
            this.tbox_intento.Name = "tbox_intento";
            this.tbox_intento.Size = new System.Drawing.Size(100, 20);
            this.tbox_intento.TabIndex = 1;
            // 
            // lab_pista
            // 
            this.lab_pista.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)));
            this.lab_pista.AutoSize = true;
            this.lab_pista.Location = new System.Drawing.Point(369, 255);
            this.lab_pista.Name = "lab_pista";
            this.lab_pista.Size = new System.Drawing.Size(38, 85);
            this.lab_pista.TabIndex = 3;
            this.lab_pista.Text = "Pistas:";
            // 
            // lab_numeros
            // 
            this.lab_numeros.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)));
            this.lab_numeros.AutoSize = true;
            this.lab_numeros.Location = new System.Drawing.Point(342, 170);
            this.lab_numeros.Name = "lab_numeros";
            this.lab_numeros.Size = new System.Drawing.Size(92, 85);
            this.lab_numeros.TabIndex = 4;
            this.lab_numeros.Text = "Numeros usados: ";
            // 
            // btn_adivinar
            // 
            this.btn_adivinar.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)));
            this.btn_adivinar.Location = new System.Drawing.Point(350, 343);
            this.btn_adivinar.Name = "btn_adivinar";
            this.btn_adivinar.Size = new System.Drawing.Size(75, 80);
            this.btn_adivinar.TabIndex = 2;
            this.btn_adivinar.Text = "Adivinar";
            this.btn_adivinar.UseVisualStyleBackColor = true;
            this.btn_adivinar.Click += new System.EventHandler(this.button1_Click);
            // 
            // lab_adivineitor
            // 
            this.lab_adivineitor.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)));
            this.lab_adivineitor.AutoSize = true;
            this.lab_adivineitor.Location = new System.Drawing.Point(360, 0);
            this.lab_adivineitor.Name = "lab_adivineitor";
            this.lab_adivineitor.Size = new System.Drawing.Size(56, 85);
            this.lab_adivineitor.TabIndex = 0;
            this.lab_adivineitor.Text = "Adivineitor";
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.CausesValidation = false;
            this.tableLayoutPanel1.ColumnCount = 1;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel1.Controls.Add(this.lab_adivineitor, 0, 0);
            this.tableLayoutPanel1.Controls.Add(this.btn_adivinar, 0, 4);
            this.tableLayoutPanel1.Controls.Add(this.lab_numeros, 0, 2);
            this.tableLayoutPanel1.Controls.Add(this.lab_pista, 0, 3);
            this.tableLayoutPanel1.Controls.Add(this.tbox_intento, 0, 1);
            this.tableLayoutPanel1.ImeMode = System.Windows.Forms.ImeMode.Katakana;
            this.tableLayoutPanel1.Location = new System.Drawing.Point(12, 12);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 5;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 20F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 20F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 20F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 20F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 20F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(776, 426);
            this.tableLayoutPanel1.TabIndex = 0;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.tableLayoutPanel1);
            this.Name = "Form1";
            this.Text = "Adivineitor";
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tableLayoutPanel1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TextBox tbox_intento;
        private System.Windows.Forms.Label lab_pista;
        private System.Windows.Forms.Label lab_numeros;
        private System.Windows.Forms.Button btn_adivinar;
        private System.Windows.Forms.Label lab_adivineitor;
        public System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
    }
}

