import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.14
import "Custombutton"
import CalcLibrary 1.0


ApplicationWindow
{
    property int winwidth: 450
    property int winheight:500
    property int heightoflistview:100
    property string operandA:""
    property string operandB:""
    property int typeOperation:-1
    property int resultwas:-1
    objectName: "CalcFrm"
    visible: true
    width: winwidth
    height: winheight
    title: qsTr("Calc")
    id: calcWindow

    function findoperation(operations)
    {
        switch (operations)
        {
        case CalcLibrary.Addition: return "+";
        case CalcLibrary.Substraction: return "-";
        case CalcLibrary.Division: return "/";
        case CalcLibrary.Multiplication: return "*";
        }
    }

    function addtodisplay(value)
    {
        var patternNum = new RegExp("^[0-9,]+$","i");
        if (patternNum.test(value) && value.length > 0 && resultwas === -1)
        {
            if (typeOperation === -1)  operandA += value; else operandB += value;
            displaycalc.text += value
        }
        else
        {
            if (value === "=" && resultwas === -1)
            {

                resultQueue.addCalc(parseFloat(operandA.replace(",",".")), parseFloat(operandB.replace(",",".")), typeOperation)
                displaycalc.text = ""
            };

            ////////// МОИ ГЛАЗА АААААА
            if (value==="+"&&typeOperation===-1&&resultwas===-1) {typeOperation=CalcLibrary.Addition;displaycalc.text+=value};
            if (value==="-"&&typeOperation===-1&&resultwas===-1) {typeOperation=CalcLibrary.Substraction;displaycalc.text+=value};
            if (value==="/"&&typeOperation===-1&&resultwas===-1) {typeOperation=CalcLibrary.Division;displaycalc.text+=value};
            if (value==="*"&&typeOperation===-1&&resultwas===-1) {typeOperation=CalcLibrary.Multiplication;displaycalc.text+=value};
            if (value==="+/-"&&resultwas===-1)
            {
                if(typeOperation === -1)
                {
                    operandA=(parseFloat(operandA)>0)?(parseFloat(operandA)*-1).toString():Math.abs(parseFloat(operandA)).toString()
                }
                if(typeOperation>=0)
                {
                    operandB=(parseFloat(operandB)>0)?(parseFloat(operandB)*-1).toString():Math.abs(parseFloat(operandB)).toString()
                }
                displaycalc.text=operandA+findoperation(typeOperation)+operandB;
            };
            if (value==="C") {operandA="";operandB="";typeOperation=-1;displaycalc.text="";resultwas=-1};
        }

    }

    RowLayout
    {
        id:resultdisplay
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        Row {
            Rectangle
            {
                id:rectdisplay

                Text
                {
                    id: displaycalc
                    padding: 5
                    color: "black"
                    font.pointSize: 15
                    horizontalAlignment: Text.AlignHCenter
                    width: rectdisplay.width
                    height:  rectdisplay.height
                    Layout.alignment:Qt.AlignHCenter
                }
                color: "#bacde2"
                width: calcWindow.width
                height: 50
                border.color: "black"
                border.width: 3
            }
        }

    }

    RowLayout
    {
        id:buttonsrow
        anchors.fill: parent
        anchors.rightMargin: 0
        anchors.bottomMargin: heightoflistview
        anchors.leftMargin: 0
        anchors.topMargin: resultdisplay.height+10
        spacing: 5
        Layout.alignment:Qt.AlignHCenter
        ColumnLayout
        {
            id: buttnumbers
            anchors.topMargin:80;
            Layout.alignment:Qt.AlignHCenter
            width:parent.width-150
            Row
            {
                id:buttonselem1
                Layout.alignment: Qt.AlignCenter
                spacing: 5
                Calcbutton
                {
                    id:butt7
                    text:"7"
                    font.bold: true
                    onClicked:addtodisplay(this.text)

                }

                Calcbutton
                {
                    id:butt8
                    text:"8"
                    font.bold: true
                    onClicked: addtodisplay(this.text)
                }
                Calcbutton
                {
                    id:but9
                    text:"9"
                    font.bold: true
                    onClicked:addtodisplay(this.text)

                }
            }
            Row
            {
                id:buttonselem2
                Layout.alignment: Qt.AlignCenter
                spacing: 5
                Calcbutton
                {
                    id:butt4
                    text:"4"
                    font.bold: true
                    onClicked: addtodisplay(this.text)

                }

                Calcbutton
                {
                    id:butt5
                    text:"5"
                    font.bold: true
                    onClicked: addtodisplay(this.text)

                }
                Calcbutton
                {
                    id:but6
                    text:"6"
                    font.bold: true
                    onClicked: addtodisplay(this.text)

                }
            }
            Row
            {
                id:buttonselem3
                Layout.alignment: Qt.AlignCenter
                spacing: 5
                Calcbutton
                {
                    id:butt1
                    text:"1"
                    font.bold: true
                    onClicked: addtodisplay(this.text)

                }

                Calcbutton
                {
                    id:butt2
                    text:"2"
                    font.bold: true
                    onClicked:addtodisplay(this.text)
                }
                Calcbutton
                {
                    id:but3
                    text:"3"
                    font.bold: true
                    onClicked: addtodisplay(this.text)

                }
            }

            Row
            {
                id:buttonselem4
                Layout.alignment: Qt.AlignCenter
                spacing: 5
                Calcbutton
                {
                    id:buttinv
                    text:"+/-"
                    onClicked:addtodisplay(this.text)

                }

                Calcbutton
                {
                    id:butt0
                    text:"0"
                    font.bold: true
                    onClicked: addtodisplay(this.text)

                }
                Calcbutton
                {
                    id:butdot
                    text:","
                    onClicked: addtodisplay(this.text)
                }
            }

        }


        ColumnLayout
        {
            id: operations
            Layout.alignment:Qt.AlignRight
            spacing: 5
            Layout.rightMargin: 10
            Calcbutton
            {
                id:buttclear
                text:"C"
                onClicked: addtodisplay(this.text)

            }
            Calcbutton
            {
                id:buttdiv
                text:"/"
                onClicked: addtodisplay(this.text)
            }
            Calcbutton
            {
                id:buttmul
                text:"*"
                onClicked: addtodisplay(this.text)

            }
            Calcbutton
            {
                id:buttsub
                text:"-"
                onClicked:addtodisplay(this.text)

            }
            Calcbutton
            {
                id:buttadd
                text:"+"
                onClicked: addtodisplay(this.text)

            }

            Calcbutton
            {
                id:buttresult
                text:"="
                onClicked: addtodisplay(this.text)
            }

        }
    }

    RowLayout
    {
        id:rowlist
        anchors.fill: parent
        anchors.rightMargin: 10
        anchors.topMargin:resultdisplay.height+buttonsrow.height+10
        anchors.leftMargin: 10
        anchors.bottomMargin: 10
        Rectangle
        {
            id:rectlistview
            ListView
            {
                leftMargin:  5
                width:rowlist.width
                model: listmodel
                clip: true
                ScrollBar.vertical:
                    ScrollBar
                {
                    active:true
                }

                Layout.alignment:Qt.AlignLeft
                height: heightoflistview-20
                delegate: Text
                {
                    text: datavalue
                    Component.onCompleted:
                    {
                        color = Qt.binding(function()
                        {
                            if (decoratation===0) return "green"
                            if (decoratation===1) return "blue"
                            if (decoratation===2) return "red"
                        });
                    }
                }
            }
            color: "white"
            Layout.fillWidth: true
            height: heightoflistview-10
            border.color: "black"
            border.width: 1
        }
    }



}
