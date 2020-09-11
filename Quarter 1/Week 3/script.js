jQuery(document).ready(function() {
              EditableTable.init();
    /*
    $("#exportpdf").click(function() {
        var doc = new jsPDF('landscape');
        //doc.autoTable({html: '#editable-sample'});
        doc.autoTable({
            html: '#editable-sample',
            startY: false,
            theme: 'grid',  
            tableWidth: 'auto',
            columnWidth: 'wrap',
            showHeader: 'everyPage',
            tableLineColor: 200,
            tableLineWidth: 0,
            columnStyles: {
            0: {columnWidth: 10}, 1: {columnWidth: 25}, 2: {columnWidth: 75}, 3:
                {columnWidth: 50}, 4: {columnWidth: 50},
            5: {columnWidth: 'auto'}, 6: {columnWidth: 50}, 7: {columnWidth: 50}, 8:
                {columnWidth: 'auto'}
            },
            headerStyles: {theme: 'grid'},
            styles: {overflow: 'linebreak', columnWidth: 'wrap',  
            fontSize: 10,
            cellPadding: 8, overflowColumns: 'linebreak'},
        });
        doc.save('table.pdf');
    });

    */
   
    //good one
    /*
    $("#exportpdf").click(function() {


            //var pdf = new jsPDF('p', 'pt', 'ledger');
            var pdf = new jsPDF('p', 'pt');
            // source can be HTML-formatted string, or a reference
            // to an actual DOM element from which the text will be scraped.
            source = $('#editable-sample')[0];


            // we support special element handlers. Register them with jQuery-style
            // ID selector for either ID or node name. ("#iAmID", "div", "span" etc.)
            // There is no support for any other type of selectors
            // (class, of compound) at this time.
            specialElementHandlers = {
                // element with id of "bypass" - jQuery style selector
                '#bypassme' : function(element, renderer) {
                    // true = "handled elsewhere, bypass text extraction"
                    return true
                }
            };
            margins = {
                top : 80,
                bottom : 60,
                left : 60,
                width : 522
            };
            // all coords and widths are in jsPDF instance's declared units
            // 'inches' in this case
            pdf.fromHTML(source, // HTML string or DOM elem ref.
            margins.left, // x coord
            margins.top, { // y coord
                'width' : margins.width, // max width of content on PDF
                'elementHandlers' : specialElementHandlers
            },

            function(dispose) {
                // dispose: object with X, Y of the last line add to the PDF
                //          this allow the insertion of new lines after html
                pdf.save('output.pdf');
            }, margins);
    });
    */

    // content is the data (a string) you'll write to file.
    // filename is a string filename to write to on server side.
    // This function uses iFrame as a buffer, it fills it up with your content
    // and prompts the user to save it out.


     $("#exporthtml").click(function() {
     
        var html_content= $('#start_save').html();
        var path = window.location.pathname;
        var page = path.split("/").pop();
        var page_name = page.split(".")[0];
        console.log(page_name);
        //var html_content= $('#editable-sample').html();
        $.ajax({
                type: 'POST',
                url: "php/write_to_html.php",
                data: {html_data: html_content,
                       html_page: page_name},
                success: function(result) {
                    console.log('the html was successfully sent to the server');
                }
        });
        alert("Finished saving to html file");

     });

    $("#exportpdf").click(function() {
       

            var doc = new jsPDF('l', 'mm', "a0");

            let source = $('#editable-sample')[0];

            var data = doc.autoTableHtmlToJson(source);

            doc.autoTable({
                html: '#editable-sample',
                theme: 'grid',
                tableWidth: 'auto',
                columnWidth: 'wrap',
                showHeader: 'everyPage',
                tableLineColor: 200,
                tableLineWidth: 0,
                bodyStyles: {minCellHeight: 30},
                didDrawCell: function(data) {
                    if (data.column.index === 4 && data.cell.raw.innerHTML != "URL") {
                        var td = data.cell.raw;
                        console.log(td);
                        console.log(td.innerHTML)
                        console.log(data.row.index);
                        // Assuming the td cells have an img element with a data url set (<td><img src="data:image/jpeg;base64,/9j/4AAQ..."></td>)
                        var img = td.getElementsByTagName('a')[0];

                        var dim = data.cell.height - data.cell.padding('vertical');
                        var textPos = data.cell.textPos;
                        doc.textWithLink(img.href, textPos.x,  textPos.y+3, {url: img.href});
                    }
                },
                headerStyles: {theme: 'grid'},
                styles: {overflow: 'linebreak', columnWidth: 'wrap',
                    fontSize: 10,
                    cellPadding: 8, overflowColumns: 'linebreak'}
            });


            /* var data = doc.autoTableHtmlToJson(source);
            var links = [];
            console.log(data);
            doc.autoTable(data.columns, data.rows, {
                bodyStyles: {
                    rowHeight: 30
                },
                didDrawCell: function(cell) {
                    console.log('fired');
                    console.log(cell);
                    if (cell.column.index === 4) {
                        console.log(cell.cell.text)
                        links.push({
                            x: cell.x,
                            y: cell.y
                        });
                        //doc.textWithLink(cell.href, cell.x, cell.y, {url: cell.href});
                    }
                }
            }); */

            /* doc.autoTable({
                html: '#editable-sample',
                theme: 'grid',  
                tableWidth: 'auto',
                columnWidth: 'wrap',
                showHeader: 'everyPage',
                tableLineColor: 200,
                tableLineWidth: 0,
                willDrawCell: function(data) {
                    if(data.column.index === 4) {
                        console.log('Reached');
                        var td = data.cell;
                        console.log(td);
                        var link = data.cell.text;
                        console.log(link);
                        var textPos = data.cell.textPos;
                        doc.textWithLink(link.href, textPos.x, textPos.y, {url: link.href});
                    }
                },
                columnStyles: {
                0: {columnWidth: 45}, 1: {columnWidth: 25, overflow: 'auto', textColor: [0,0,255]}, 2: {columnWidth: 'auto'}, 3:
                    {columnWidth: 50}, 4: {columnWidth: 50},
                5: {columnWidth: 'auto'}, 6: {columnWidth: 50}, 7: {columnWidth: 'auto'}, 8:
                    {columnWidth: 10}, 9: {columnWidth: 10}, 10: {columnWidth: 10}
                },
                headerStyles: {theme: 'grid'},
                styles: {overflow: 'linebreak', columnWidth: 'wrap',  
                fontSize: 10,
                cellPadding: 8, overflowColumns: 'linebreak'},
            }); */
            doc.save('output.pdf');
            alert("Finished saving to pdf file");

     

    });

});