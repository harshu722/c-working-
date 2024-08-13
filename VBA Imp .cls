VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
END
Attribute VB_Name = "Sheet1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = True
Function Discount(Quantity, Price)

If Quantity > 25 Then
Discount = Quantity * Price * 0.2

Else
Discount = 0
End If
End Function

Sub ClearContent()
Answer = MsgBox("Confirm you want to Clear?", vbYesNo)
If Answer = vbYes Then
Rows("6:" & Rows.Count).ClearContents
Else
Exit Sub
End If
End Sub


Sub SendEmail()
    Dim OutApp As Object
    Dim OutMail As Object

    ' Error handling to check if Outlook is installed
    On Error Resume Next
    Set OutApp = CreateObject("Outlook.Application")
    On Error GoTo 0
    
    If OutApp Is Nothing Then
        MsgBox "Outlook is not installed on this computer.", vbExclamation
        Exit Sub
    End If

    Set OutMail = OutApp.CreateItem(0)

    With OutMail
        .To = "kollurusaharsh@gmail.com"
        .Subject = "Excel File"
        .Body = "This is for Testing Purpose"
        .Attachments.Add "C:\Users\saharsh\OneDrive\Documents\VBA Important\Excel - VBA - Start.xlsx"
        .Display
    End With

    Set OutMail = Nothing
    Set OutApp = Nothing
End Sub

