import Logger as log

if __name__ == '__main__':

    print('TODO')

    # TODO create a logger and add some items
    logger = log.Logger()

    logger.add_item(log.Level.Warning, "This is a warning log !")
    logger.add_item(log.Level.Info, "This is an info log !")
    logger.add_item(log.Level.Error, "This is an error log !")
    logger.add_item(log.Level.Info, "This is a second info log !")
    logger.add_item(log.Level.Warning, "This is a second warning log !")

    print(logger.report_by_added())

    print(logger.report_by_level())

