   M S B A M L   `   `   `  ����O  KConversor_de_divisas, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null;"clr-namespace:Conversor_de_divisasConversor_de_divisas  5   	   %    Conversor_de_divisas.MainWindow   5   	   R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   4local"clr-namespace:Conversor_de_divisas     5   	     � Title$  
MainWindow��5   	   $	��450��6   $	��800��6)   .��5	      �  � ColumnDefinitions 5
   
   �� 5      $��* �6   �� 5      $��* �6    � RowDefinitions 5   
   �� 5      $��* �6   �� 5      $��* �6   �� 5      $��* �6   �� 5      $��* �6   .+�5   
   �� $��Conversor de divisas��6   $��Center=�6/   $��Center=�6L   $��2��6g   �� 5   
   -   5         ��Name$ txtCantidad��5      $��Center=�6'   $��Center=�6D   $��1��6_   $��1��6l   {�.  6|   �� 5   
   -   5        $ txtCantidadTransformada��5      $��Center=�63   $��Center=�6P   $��1��6k   �� 5   
   -   5         ��Name$ txtDe��5      $��De��6   $��Center=�6,   $	��Top=�6I   $��2��6a   $��0��6n   �� 5   
   -   5         ��Name$
 ARS1��5      $��Center=�6   $��Center=�6<   $��2��6W   $��0��6d   $��64��6�   $��64��6�   ��5      �� 5       �� ImageSource$B <https://www.worldometers.info/img/flags/small/tn_ar-flag.gif��6    j� Stretch$ UniformToFill=�6h   5      �� 5   
   -   5        $
 USD1��5      $
��Left=�6   $��Center=�6:   $��2��6U   $��0��6b   $��64��6�   $��64��6�   $��99,0,0,0q�6�   ��5      �� 5      $B <https://www.worldometers.info/img/flags/small/tn_us-flag.gif��6   $
 Fill=�6h   5!      �� 5"   
   -   5        $
 EUR1��5"      $
��Left=�6   $��Center=�6:   $��2��6U   $��0��6b   $��64��6�   $��64��6�   $��	237,0,0,0q�6�   ��5#      �� 5$      $o ihttps://upload.wikimedia.org/wikipedia/commons/thumb/b/b7/Flag_of_Europe.svg/255px-Flag_of_Europe.svg.png��6   $ UniformToFill=�6�   5&      �� 5'   
   -   5        $
 txtA��5'      $��A��6   $��Center=�6*   $	��Top=�6G   $��2��6_   $��1��6l   �� 5(   
   -   5        $
 ARS2��5(      $��Center=�6   $��Center=�6<   $��2��6W   $��64��6w   $��64��6�   $��1��6�   ��5)      �� 5*      $B <https://www.worldometers.info/img/flags/small/tn_ar-flag.gif��6   $ UniformToFill=�6h   5,      �� 5-   
   -	   5        $
 USD2��5-      $
��Left=�6   $��Center=�6:   $��2��6U   $��1��6b   $��64��6�   $��64��6�   $��99,0,0,0q�6�   ��5.      �� 5/      $B <https://www.worldometers.info/img/flags/small/tn_us-flag.gif��6   $
 Fill=�6h   51      �� 52   
   -
   5        $
 EUR2��52      $
��Left=�6   $��Center=�6:   $��2��6U   $��1��6b   $��64��6�   $��64��6�   $��	237,0,0,0q�6�   ��53      �� 54      $ UniformToFill=�6   $o ihttps://upload.wikimedia.org/wikipedia/commons/thumb/b/b7/Flag_of_Europe.svg/255px-Flag_of_Europe.svg.png��65   56      �� 57   
   -   5        $ btnConvertir��57      $��	Convertir��6'   $��Center=�6;   $��Center=�6X   $��3��6s   $��2��6�   6�   58      59      