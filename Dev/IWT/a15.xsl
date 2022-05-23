<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:template match="/">
        <html>
            <body>
                <h2>BOOKS</h2>
                <table border="1">
                    <tr bgcolor="green">
                        <th align="left">title</th>
                        <th align="left">author</th>
                        <th align="left">edition</th>
                        <th align="left">price</th>
                    </tr>
                    <xsl:for-each select="BOOKDATA/BOOK">
                        <tr>
                            <td>
                                <xsl:value-of select="TITLE" />
                            </td>
                            <td >
                                <xsl:value-of select="AUTHOR" />
                            </td>
                            <td>
                                <xsl:value-of select="EDITION" />
                            </td>
                            <td >
                                <xsl:value-of select="PRICE" />
                            </td>
                        </tr>
                    </xsl:for-each>
                    
                </table>
            </body>
        </html>
    </xsl:template>
</xsl:stylesheet>